from django.urls import path

from . import views


urlpatterns = [
    path('register', views.RegisterView.as_view(), name='register'),
    path('login', views.LoginView.as_view(), name='login'),
    path('logout', views.LogoutView.as_view(), name='logout'),
    path('administration', views.AdminView.as_view(), name='admin'),
    path('', views.home, name='home'),
    path(r'profile/<pk>', views.UserUpdate.as_view(), name='profile'),

]