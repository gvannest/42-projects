from django.shortcuts import render, HttpResponse
from ex00.query_create import query_create_table, result_query_execute, connection_db
from ex02.views import define_query, ft_display

# Create your views here.


def init(request):

    query = query_create_table("ex04_movies")

    res = result_query_execute(query)

    return HttpResponse(res)


def populate(request):

    return HttpResponse(define_query("ex04_movies"))


def display(request):

    return HttpResponse(ft_display("ex04_movies"))



def remove_form(table):

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


def delete_item(movie_id, table):

    query = """DELETE FROM {} WHERE episode_nb={}""".format(table, movie_id)

    res_del = result_query_execute(query)

    return res_del



def remove(request):

    film_to_remove = request.POST.get('movie', None)
    if film_to_remove:
        res_del = delete_item(int(film_to_remove), "ex04_movies")
        if res_del != "OK":
            return HttpResponse("No data available")

    res = remove_form("ex04_movies")
    if type(res) == str:
        return HttpResponse(res)

    return  render(request, "ex04.html", {'movies': res})


