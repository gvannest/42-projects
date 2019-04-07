from django.shortcuts import render, HttpResponse
from .models import Planets, People
# Create your views here.



def display(request):

    try:
        response = People.objects.filter(homeworld__climate__contains='windy')\
            .values('name', 'homeworld__name', 'homeworld__climate')\
            .order_by('name')
    except Exception as e:
        return HttpResponse(e)

    if not response:
        return HttpResponse("No data available, please use the following command line before use:\n\
                            ./manage.py loaddata ex09/resources/ex09_initial_data.json")


    return render(request, "ex09_display.html", {'response':response})


