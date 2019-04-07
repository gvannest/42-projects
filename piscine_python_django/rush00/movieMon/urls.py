from django.urls import path, re_path
from . import views

urlpatterns = [
    path('', views.title_screen),
    re_path(r'^worldmap/?$', views.world_map),
    path('battle/<str:title>/', views.battle),
    path('load_game/', views.load),
    path('moviedex/', views.moviedex),
    path('moviedex/<str:title>', views.details),
    path('options/', views.options),
    path('save_game/', views.save)

]