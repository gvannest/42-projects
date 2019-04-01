from django.shortcuts import render, HttpResponse
from ex03.views import display_table, get_list_movies
from .models import Movies
from datetime import datetime

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


def display_table(response):


    if not response:
        return HttpResponse("No data available")

    result = '<table cellpadding="10px"><tr><th>Title</th><th>Episode_nb</th><th>Opening_crawl</th>' \
             '<th>Director</th><th>Poducer</th><th>Date</th><th>Created</th><th>Updated</th></tr>'

    for r in response:
        result += "<tr>"
        for m in [r.title, r.episode_nb, r.opening_crawl, r.director, r.producer, r.release_date, r.created, r.updated]:
            result += '<td>{}</td>'.format(m)
        result += "</tr>"
    result += "</table>"

    return result




def display(request):
    response = Movies.objects.all()
    return HttpResponse(display_table(response))


def add_item(movie_id, text):

    r = Movies.objects.filter(episode_nb=movie_id)
    r.update(opening_crawl=text, updated=datetime.now())

    return None

def update(request):

    if request.method == 'POST':
        movie_id = request.POST.get('movie', None)
        movie_text = request.POST.get('text_movie', None)
        add_item(int(movie_id), movie_text)

    res = Movies.objects.all()
    if not res:
        return HttpResponse("No data available")


    return render(request, "ex07.html", {'movies': res})