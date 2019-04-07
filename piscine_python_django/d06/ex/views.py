from django.shortcuts import render, HttpResponse, redirect
from django.contrib.auth.decorators import permission_required, login_required
from django.contrib.auth.models import User, Permission, Group
from django.contrib import auth
from django.conf import settings
from .form import SignupForm, LoginForm, TipForm
from .models import Tip, Upvote, Downvote

import random

User = auth.get_user_model()



# Create your views here.

@login_required
def delete_content(request):

    if request.user.has_perm('ex.delete_tip'):
        tip = Tip.objects.get(id=request.POST.get('delete'))
        if tip.auteur == request.COOKIES.get('mycookie'):
            tip.delete()

    return None


def vote_tip(type, id, request):

    username = request.COOKIES.get('mycookie')

    tip = Tip.objects.get(id=id)
    upvote_user = tip.upvote.filter(vote_user=username)
    downvote_user = tip.downvote.filter(vote_user=username)

    if type == 'upvote':
        if upvote_user:
            for vote in upvote_user:
                tip.upvote.remove(vote)
        elif not downvote_user:
            vote = Upvote(vote_user=username)
            vote.save()
            tip.upvote.add(vote)

    if type == 'downvote':
        if request.user.has_perm('ex.downvote') and tip.auteur == username:
            if downvote_user:
                for vote in downvote_user:
                    tip.downvote.remove(vote)
            elif not upvote_user:
                vote = Downvote(vote_user=username)
                vote.save()
                tip.downvote.add(vote)

    return None



def tip_form(request):

    tip_form = TipForm(request.POST)
    if tip_form.is_valid():
        auteur = request.COOKIES.get('mycookie')
        content = tip_form.cleaned_data['contenu']
        t = Tip(contenu=content, auteur=auteur)
        t.save()
        tip_form = TipForm()

    else:
        tip_form = TipForm()

    return tip_form



def welcome(request):

    user = random.choice(settings.USER_NAMES)

    if request.user.is_authenticated:
        request.user.rep_downvote()
        request.user.rep_delete()



    if request.method == "POST":
        if 'delete' in request.POST:
            delete_content(request)
        elif 'upvote' in request.POST:
            vote_tip('upvote', request.POST.get('upvote'), request)
        elif 'downvote' in request.POST:
            vote_tip('downvote', request.POST.get('downvote'), request)
        elif request.user.is_authenticated:
            form = tip_form(request)

    tips = Tip.objects.all()

    dic_votes = {}
    for tip in tips:
        nb_up = tip.upvote.count()
        nb_down = tip.downvote.count()
        if nb_up > nb_down:
            dic_votes[tip] = (nb_up - nb_down, 0)
        else:
            dic_votes[tip] = (0, nb_down - nb_up)


    if not request.COOKIES.get('mycookie'):
        request.COOKIES['mycookie'] = user
        response = render(request, "ex00.html", {'dic_tips':dic_votes})
        response.set_cookie('mycookie', user, max_age=settings.MAX_AGE_COOKIE)
        return response


    form = TipForm()

    return render(request, "ex00.html", {'dic_tips':dic_votes, 'tip_form':form})


def inscription(request):

    if request.user.is_authenticated:
        return redirect('/')

    if request.method == "POST":
        form = SignupForm(request.POST)
        message = ""

        if form.is_valid():
            username = form.cleaned_data['username']
            if User.objects.filter(username=username).exists():
                message = "Username already exists"
            else:
                u = User.objects.create_user(username, None, form.cleaned_data['password'])
                u.save()
                username = form.cleaned_data['username']
                password = form.cleaned_data['password']
                user = auth.authenticate(username=username, password=password)

                if user and user.is_active:
                    auth.login(request, user)
                    response = redirect('/')
                else:
                    form._errors['username'] = ['This user does not exist']

                response.set_cookie('mycookie', u.username)
                return response

        return render(request, 'ex01_signup.html', {'form':form, 'message':message})

    form = SignupForm()
    return render(request,'ex01_signup.html', {'form':form})



def connexion(request):

    if request.user.is_authenticated:
        return redirect('/')

    if request.method == "POST":
        form = LoginForm(request.POST)
        if form.is_valid():
            username = form.cleaned_data['username']
            password = form.cleaned_data['password']
            user = auth.authenticate(username=username, password=password)

            if user and user.is_active:
                auth.login(request, user)
                response = redirect('/')
                response.set_cookie('mycookie', user.username)
                return response

            else:
                form._errors['username'] = ['This user does not exist']
    else:

        form = LoginForm()
    return render(request, 'ex01_login.html', {'form': form})


def deconnexion(request):
    auth.logout(request)
    response = redirect('/')
    response.delete_cookie('mycookie')

    return response

