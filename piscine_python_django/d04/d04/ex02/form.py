from django import forms

class MyForm(forms.Form):
    name = forms.CharField(required = True)
    email = forms.EmailField(required = True)