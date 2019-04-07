from django.db import models

# Create your models here.

class Movies(models.Model):
    title = models.CharField(max_length=64)
    episode_nb = models.IntegerField(primary_key=True)
    opening_crawl = models.TextField(blank=True)
    director = models.CharField(max_length=32)
    producer = models.CharField(max_length=128)
    release_date = models.DateField()

    def __str__(self):
        return "{}".format(self.title)