from django import forms
from .models import UserFavouriteArticle


class AddFavForm(forms.ModelForm):
    class Meta:
        model = UserFavouriteArticle
        fields = []



