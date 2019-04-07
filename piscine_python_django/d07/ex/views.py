from django.shortcuts import render, HttpResponse, reverse
from django.views.generic import DetailView, ListView, FormView, RedirectView
from django.contrib.auth.forms import AuthenticationForm, UserCreationForm
from .models import Article, UserFavouriteArticle
from .form import AddFavForm
from django.contrib.auth import login, logout
from django.http import HttpResponseRedirect
from django.views.generic.edit import CreateView, FormMixin


# Create your views here.


class ArticleList(ListView):
    model = Article



class LoginView(FormView):
    template_name = 'ex/login.html'
    form_class = AuthenticationForm
    success_url = '/'
    def form_valid(self, form):
        login(self.request, form.get_user())
        return HttpResponseRedirect(self.get_success_url())


class Publication(ListView):
    template_name = 'ex/publication_list.html'
    def get_queryset(self):
        if self.request.user.is_authenticated:
            return Article.objects.filter(author=self.request.user)


class DetailView(DetailView, FormMixin):
    model = Article
    template_name = 'ex/detail_list.html'
    form_class = AddFavForm
    success_url = '/'

    def post(self, request, *args, **kwargs):
        id = self.kwargs['pk']
        a = UserFavouriteArticle.objects.create(article_id=id, user=self.request.user)
        a.article.id = id
        form = self.get_form()
        if form.is_valid():
            a.article.author = self.request.user
            a.save()
            return self.form_valid(form)
        else:
            return self.form_invalid(form)


class LogoutView(RedirectView):
    def get_redirect_url(self, *args, **kwargs):
        logout(self.request)
        return '/'


class FavouriteView(ListView):
    template_name = 'ex/favourites_list.html'

    def get_queryset(self):
        if self.request.user.is_authenticated:
            return UserFavouriteArticle.objects.filter(user=self.request.user)


class RegisterView(CreateView):
    template_name = 'ex/register.html'
    form_class = UserCreationForm


class ArticleCreate(CreateView):
    model = Article
    fields = ['title', 'synopsis', 'content']
    success_url = '/'

    def form_valid(self, form):
        self.object = form.save(commit=False)
        self.object.author = self.request.user
        self.object.save()
        return HttpResponseRedirect(self.get_success_url())

