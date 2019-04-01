from django.shortcuts import render, HttpResponse
from ex03.views import display_table, get_list_movies
from .models import Movies
# Create your views here.


def fill_table(query_post_list):

    res = ''
    for e in query_post_list:
        m = Movies(
            episode_nb=e[0],
            title=e[1],
            director=e[2],
            producer=e[3],
            release_date=e[4]
        )
        try:
            m.save()
        except Exception as e:
            res += "FAIL ----  {0:} : &nbsp;&nbsp;&nbsp;{1}<br>".format(m, e)
        else:
            res += "OK  -----  {}<br>".format(m)

    return res


def populate(request):
    list_movies = get_list_movies()

    return HttpResponse(fill_table(list_movies))



def display(request):
    response = Movies.objects.all()
    return HttpResponse(display_table(response))





def delete_item(movie_id, table):

    r = Movies.objects.filter(episode_nb=movie_id)
    r.delete()

    return None

def remove(request):

    film_to_remove = request.POST.get('movie', None)
    if film_to_remove:
        delete_item(int(film_to_remove), "ex04_movies")

    res = Movies.objects.all()
    if not res:
        return HttpResponse("No data available")


    return render(request, "ex05.html", {'movies': res})
