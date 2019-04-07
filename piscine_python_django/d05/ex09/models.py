from django.db import models

# Create your models here.

class Planets(models.Model):
    name = models.CharField(max_length=64, unique=True)
    climate = models.TextField(blank=True)
    diameter = models.IntegerField()
    orbital_period = models.IntegerField()
    population = models.BigIntegerField()
    rotation_period = models.IntegerField()
    surface_water = models.FloatField()
    climate = models.TextField(blank=True)
    created = models.DateTimeField(auto_now_add=True, null=True)
    updated = models.DateTimeField(auto_now=True, null=True)

    def __str__(self):
        return "{}".format(self.name)


class People(models.Model):
    name = models.CharField(max_length=64, unique=True)
    birth_year = models.CharField(max_length=32)
    gender = models.CharField(max_length=32)
    eye_color = models.CharField(max_length=32)
    height = models.IntegerField()
    mass = models.FloatField()
    homeworld = models.ForeignKey('Planets', on_delete=models.PROTECT, max_length=64)
    created = models.DateTimeField(auto_now_add=True, null=True)
    updated = models.DateTimeField(auto_now=True, null=True)

    def __str__(self):
        return "{}".format(self.name)