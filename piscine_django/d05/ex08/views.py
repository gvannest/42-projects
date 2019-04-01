from django.shortcuts import render, HttpResponse

# Create your views here.


def query_create_table1(table):
    query = """ CREATE TABLE IF NOT EXISTS {} (
            id serial PRIMARY KEY
            name varchar(64) UNIQUE NOT NULL,
            climate text,
            diameter int,
            orbital period int,
            population int
            director varchar(32) NOT NULL,
            producer varchar(128) NOT NULL,
            release_date date NOT NULL,
            created TIMESTAMP DEFAULT NOW(),
            updated TIMESTAMP DEFAULT NOW()
            )
            """.format(table)
    return query


def init(request):

    query = query_create_table("ex08_planets")

    res = result_query_execute(query)

    return HttpResponse(res)