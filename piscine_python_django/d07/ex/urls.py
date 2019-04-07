from django.urls import path, re_path

from . import views


urlpatterns = [
    path('articles', views.ArticleList.as_view(), name='articles'),
    path('', views.ArticleList.as_view()),
    path('login', views.LoginView.as_view(), name='login'),
    path('publications', views.Publication.as_view(), name='publications'),
    re_path(r'detail/(?P<pk>[0-9]+)', views.DetailView.as_view(), name='detail'),
    path('logout', views.LogoutView.as_view(), name='logout'),
    path('favourites', views.FavouriteView.as_view(), name='favourites'),
    path('register', views.RegisterView.as_view(), name='register'),
    path('publish', views.ArticleCreate.as_view(), name='publish'),

]