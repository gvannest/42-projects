from django import forms
from .models import Tip


class SignupForm(forms.Form):
    username = forms.CharField(required=True)
    password = forms.CharField(required=True, widget=forms.PasswordInput())
    verification_password = forms.CharField(required=True, widget=forms.PasswordInput())

    def clean(self):
        cleaned_data = super(SignupForm, self).clean()
        mdp = cleaned_data.get('password')
        mdp_verif = cleaned_data.get('verification_password')

        if mdp != mdp_verif:
                raise forms.ValidationError(
                    "Les mots de passe ne sont pas concordants"
                )

        return cleaned_data


class LoginForm(forms.Form):
    username = forms.CharField(required=True)
    password = forms.CharField(required=True, widget=forms.PasswordInput())



class TipForm(forms.ModelForm):
    class Meta:
        model = Tip
        fields = ['contenu']



