from django.shortcuts import render, HttpResponse
from .models import Movies


# Create your views here.

def get_list_movies():

    query_post_list = [
        (1, 'The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19'),
        (2, 'Attack of the Clones', 'George Lucas', 'Rick McCallum', '2002-05-16'),
        (3, 'Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19'),
        (4, 'A New Hope', 'George Lucas', 'Gary Kurtz, Rick McCallum', '1977-05-25'),
        (5, 'The Empire Strikes Back', 'Irvin Kershner', 'Gary Kutz, Rick McCallum', '1980-05-17'),
        (6, 'Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, Georges Lucas, Rick McCallum', '1983-05-25'),
        (7, 'The Force Awakens', 'J. J Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11')
    ]

    return query_post_list


def fill_table(query_post_list):

    res = ''
    for e in query_post_list:
        m = Movies(
            episode_nb = e[0],
            title = e[1],
            director = e[2],
            producer = e[3],
            release_date = e[4]
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
             '<th>Director</th><th>Poducer</th><th>Date</th></tr>'

    for r in response:
        result += "<tr>"
        for m in [r.title, r.episode_nb, r.opening_crawl, r.director, r.producer, r.release_date]:
            result += '<td>{}</td>'.format(m)
        result += "</tr>"
    result += "</table>"

    return result

def display(request):
    response = Movies.objects.all()
    return HttpResponse(display_table(response))




