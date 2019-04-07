from django.shortcuts import render, redirect, HttpResponseRedirect
from django.views.generic.edit import FormMixin
from django.views.generic import DetailView, ListView, FormView, RedirectView, CreateView
from django.views.generic.list import MultipleObjectMixin
from django.contrib.auth import REDIRECT_FIELD_NAME, login
from forum.models import Post
from django.contrib.auth.forms import AuthenticationForm, UserCreationForm
from django.contrib.auth import REDIRECT_FIELD_NAME, login, logout
from forum.form import PostForm

# Create your views here.

class PostList(ListView):
    model = Post
    paginate_by = 10

class PostDetail(DetailView, FormMixin):
    model = Post
    form_class = PostForm
    fields = ['content']
    template_name = 'forum/post_detail.html'
    success_url = '/post'

    def post(self, request, *args, **kwargs):
        id = self.kwargs['pk']
        print('id : ' + id)
        content = request.POST['content']
        current_post = Post.objects.get(id=id)
        if current_post.parent:
            title = "Answer to comment #" + id
        else:
            title = "Answer to post #" + id
        parent = Post.objects.get(id=id)
        print('content :' + content)
        a = Post.objects.create(content=content, author=self.request.user, parent=parent, title=title)
        form = self.get_form()
        if form.is_valid():
            a.save()
            return self.form_valid(form)
        else:
            return self.form_invalid(form)

class NewPost(CreateView):
    template_name = 'forum/new_post.html'
    model = Post
    fields = ['title', 'content']

    def form_valid(self, form):
        """
        The user has provided valid credentials (this was checked in AuthenticationForm.is_valid()). So now we
        can log him in.
        """
        #self.author = self.request.user.username
        content = form.cleaned_data['content']
        title = form.cleaned_data['title']
        new_post = Post(title=title, author=self.request.user, content=content)
        new_post.save()
        
        return HttpResponseRedirect('/post')