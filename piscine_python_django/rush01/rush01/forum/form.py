from django import forms
from forum.models import Post


class PostForm(forms.ModelForm):
    class Meta:
        model = Post
        fields = ['content']