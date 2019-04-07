from django.db import models
from django.contrib.auth.models import AbstractUser, Permission


# Create your models here.


class Upvote(models.Model):
    vote_user = models.CharField(max_length=128)

class Downvote(models.Model):
    vote_user = models.CharField(max_length=128)


class Tip(models.Model):
    contenu = models.CharField(max_length=128)
    auteur = models.TextField(max_length=64)
    date = models.DateTimeField(auto_now_add=True)
    upvote = models.ManyToManyField('Upvote')
    downvote = models.ManyToManyField('Downvote')
    class Meta:
        permissions = (('downvote', 'can_downvote'),)


class UserRep(AbstractUser):

    def calc_reputation(self):
        up_votes = 0
        for tip in Tip.objects.filter(auteur=self.username):
            up_votes += tip.upvote.count()
        down_votes = 0
        for tip in Tip.objects.filter(auteur=self.username):
            down_votes += tip.downvote.count()
        reputation = up_votes*5 - down_votes*2
        return reputation

    def rep_downvote(self):
        perm = Permission.objects.get(codename='downvote')
        if self.calc_reputation() > 14:
            self.user_permissions.add(perm)
        else:
            self.user_permissions.remove(perm)



    def rep_delete(self):
        perm = Permission.objects.get(codename='delete_tip')
        if self.calc_reputation() > 29:
            self.user_permissions.add(perm)
        else :
            self.user_permissions.remove(perm)


    def __str__(self):
        return "{}  ----- reputation : {}".format(self.username, self.calc_reputation())









