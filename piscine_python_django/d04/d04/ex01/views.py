from django.shortcuts import render, HttpResponse


def django(request):
    return render(request, "ex01/django.html", {'title': 'Ex01 : Django, framework web.'})



def affichage(request):
    return render(request, "ex01/affichage.html", {'title': 'Ex01 : Processus d’affichage d’une page statique.'})



def templates(request):
    return render(request, "ex01/templates.html", {'title': 'Ex01 : Moteur de template.'})
