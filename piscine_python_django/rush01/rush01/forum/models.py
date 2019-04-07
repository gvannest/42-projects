from django.db import models
from django.contrib.auth import get_user_model

User = get_user_model()

# Create your models here.


# class Comment(models.Model):
#     author = models.ForeignKey(User, on_delete=models.CASCADE)
#     post = models.ForeignKey('post', on_delete=models.CASCADE)
#     content = content = models.TextField()
#     created = models.DateTimeField(auto_now_add=True)
#     answer = models.ForeignKey('Comment', on_delete=models.CASCADE)


class Post(models.Model):
    parent = models.ForeignKey('self', on_delete=models.CASCADE, null=True, blank=True)
    title = models.CharField(max_length=64, null=True)
    author = models.ForeignKey(User, on_delete=models.CASCADE)
    created = models.DateTimeField(auto_now_add=True)
    content = models.TextField()
