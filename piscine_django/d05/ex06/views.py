from django.shortcuts import render, HttpResponse
from ex00.query_create import query_create_table, result_query_execute, connection_db
from ex02.views import define_query, ft_display

# Create your views here.


def query_create_table(table):
    query = """ CREATE TABLE IF NOT EXISTS {} (
            title varchar(64) UNIQUE NOT NULL,
            episode_nb int PRIMARY KEY,
            opening_crawl text,
            director varchar(32) NOT NULL,
            producer varchar(128) NOT NULL,
            release_date date NOT NULL,
            created TIMESTAMP DEFAULT NOW(),
            updated TIMESTAMP DEFAULT NOW()
            )
            """.format(table)
    return query


def init(request):

    query = query_create_table("ex06_movies")

    res = result_query_execute(query)

    return HttpResponse(res)



def populate(request):

    return HttpResponse(define_query("ex06_movies"))


def display(request):

    return HttpResponse(ft_display("ex06_movies"))



def get_form(table):

    query = """SELECT * from {}""".format(table)

    try:
        conn = connection_db()
        curr = conn.cursor()
        curr.execute(query)
        response = curr.fetchall()
        conn.close()

    except Exception as e:
        return "No data available"

    else:
        if not response:
            return "No data available"
        else:
            return response

#
def add_item(movie_id, text, table):

    query = """UPDATE {} SET opening_crawl = '{}' WHERE episode_nb={}""".format(table, text, movie_id)
    res_up = result_query_execute(query)

    return res_up



def update(request):

    if request.method == 'POST':
        movie = request.POST.get('movie', None)
        text = request.POST.get('text_movie', None)
        res_up = add_item(int(movie), str(text), "ex06_movies")
        if res_up != "OK":
            return HttpResponse("No data available")

    res = get_form("ex06_movies")
    if type(res) == str:
        return HttpResponse(res)

    return  render(request, "ex06.html", {'movies': res})