from django.shortcuts import render, HttpResponse


def markdown(request):
    return render(request, "ex00/index.html")
