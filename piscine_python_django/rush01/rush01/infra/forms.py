from .models import MyUser
from django import forms
from django.contrib.auth.forms import UserCreationForm



class SignUpForm(UserCreationForm):
    class Meta:
        model = MyUser
        fields = ['username', 'password1', 'password2']


class ProfileForm(forms.Form):
    class Meta:
        model = MyUser
        fields = ['last_name', 'first_name', 'email', 'description', 'profile_image']