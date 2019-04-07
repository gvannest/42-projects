from django.db import models
from django.contrib.auth.models import AbstractUser

# Create your models here



class MyUser(AbstractUser):
    description = models.TextField()
    image = models.ImageField(upload_to='files', blank=True, null=True)