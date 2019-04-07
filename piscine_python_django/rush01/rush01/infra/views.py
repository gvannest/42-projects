from django.shortcuts import render, HttpResponse, reverse
from django.views.generic import DetailView, ListView, FormView, RedirectView
from django.contrib.auth.forms import AuthenticationForm, UserCreationForm
from django.contrib.auth import login, logout
from django.http import HttpResponseRedirect
from django.views.generic.edit import CreateView, FormMixin, UpdateView
from django.contrib.auth import get_user_model
from .forms import SignUpForm

User = get_user_model()


# Create your views here.


class LoginView(FormView):
    template_name = 'infra/login.html'
    form_class = AuthenticationForm
    success_url = '/'

    def form_valid(self, form):
        login(self.request, form.get_user())
        return HttpResponseRedirect(self.get_success_url())


class LogoutView(RedirectView):
    def get_redirect_url(self, *args, **kwargs):
        logout(self.request)
        return '/'


class RegisterView(CreateView):
    template_name = 'infra/register.html'
    form_class = SignUpForm
    success_url = '/'

    def form_valid(self, form):
        form.save()
        login(self.request, User.objects.get(
            username=form.cleaned_data['username']))
        return HttpResponseRedirect(self.success_url)



class AdminView(ListView):
    template_name = 'infra/profile_list.html'

    def get_queryset(self):
        if self.request.user.is_staff:
            return User.objects.all()


class UserUpdate(UpdateView):
    model = User
    fields = ['last_name', 'first_name', 'email', 'description', 'image']
    # form_class = ProfileForm
    template_name = 'infra/detail_profile.html'
    success_url = '/'




def home(request):
    return render(request, "infra/welcome.html")
