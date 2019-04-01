from django.shortcuts import render, HttpResponse
from ex00.query_create import query_create_table, result_query_execute, connection_db

# Create your views here.


def init(request):
    query = query_create_table("ex02_movies")
    res = result_query(query)

    return HttpResponse(res)





def define_query(table):

    query_post_list = [
        (1, 'The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19'),
        (2, 'Attack of the Clones', 'George Lucas', 'Rick McCallum', '2002-05-16'),
        (3, 'Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19'),
        (4, 'A New Hope', 'George Lucas', 'Gary Kurtz, Rick McCallum', '1977-05-25'),
        (5, 'The Empire Strikes Back', 'Irvin Kershner', 'Gary Kutz, Rick McCallum', '1980-05-17'),
        (6, 'Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, Georges Lucas, Rick McCallum', '1983-05-25'),
        (7, 'The Force Awakens', 'J. J Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11')
    ]

    string_results = ''

    for query in query_post_list:

        query_str = """
        INSERT INTO {0}(episode_nb, title, director, producer, release_date) VALUES {1}
        """.format(table, query)


        res = str(result_query_execute(query_str))

        if res == "OK":
            string_results += "OK  -----  {}<br>".format(query[1])
        else:
            string_results += "FAIL ----  {0:} : &nbsp;&nbsp;&nbsp;{1}<br>".format(query[1], res)

    return string_results


def populate(request):

    return HttpResponse(define_query("ex02_movies"))



def ft_display(table):

    query = """SELECT * from {}""".format(table)

    try:
        conn = connection_db()
        curr = conn.cursor()
        curr.execute(query)
        response = curr.fetchall()
        conn.close()

    except Exception as e:
        result = 'No data available'

    else:
        if not response:
            result = "No data available"
        else:
            result = '<table cellpadding="10px"><tr><th>Title</th><th>Episode_nb</th><th>Opening_crawl</th>' \
                     '<th>Director</th><th>Poducer</th><th>Date</th></tr>'
            for e in response:
                result += "<tr>"
                for item in e:
                    result += '<td>{}</td>'.format(item)
                result += "</tr>"
            result += "</table>"


    return result




def display(request):

    return HttpResponse(ft_display("ex02_movies"))