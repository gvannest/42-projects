from django.urls import path, re_path

from . import views

urlpatterns = [
    re_path('/django/?$', views.django, name="django"),
    re_path('/affichage/?$', views.affichage, name="affichage"),
    re_path('/templates/?$', views.templates, name="templates"),
]