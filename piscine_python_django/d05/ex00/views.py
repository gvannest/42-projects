from django.shortcuts import render, HttpResponse
from .query_create import query_create_table, result_query_execute

# Create your views here.



def init(request):

    query = query_create_table("ex00_movies")

    res = result_query_execute(query)

    return HttpResponse(res)


