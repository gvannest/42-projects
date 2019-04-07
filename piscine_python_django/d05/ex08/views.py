from django.shortcuts import render, HttpResponse
from ex00.query_create import query_create_table, result_query_execute, connection_db

# Create your views here.


def query_create_table1(table):

    query = """ CREATE TABLE IF NOT EXISTS {} (
            id serial PRIMARY KEY,
            name varchar(64) UNIQUE NOT NULL,
            climate text,
            diameter int,
            orbital_period int,
            population bigint,
            rotation_period int,
            surface_water float,
            terrain varchar(128)
            )
            """.format(table)
    return query



def query_create_table2(table):

    query = """ CREATE TABLE IF NOT EXISTS {} (
            id serial PRIMARY KEY,
            name varchar(64) UNIQUE NOT NULL,
            birth_year varchar(32),
            gender varchar(32),
            eye_color varchar(32),
            hair_color varchar(32),
            height int,
            mass float,
            homeworld varchar(64) REFERENCES ex08_planets(name)
            )
            """.format(table)
    return query


def init(request):

    query1 = query_create_table1("ex08_planets")
    query2 = query_create_table2("ex08_people")

    res1 = result_query_execute(query1)
    res2 = result_query_execute(query2)

    return render(request, "ex08.html", {'res1':res1, 'res2':res2})




def result_query(filepath, table, columns):

    try:
        conn = connection_db()
        curr = conn.cursor()
        with open(filepath, 'r') as file:
            curr.copy_from(file, table, columns=columns, null='NULL')

    except Exception as e:
        print(e)
        res = str(e)
    else:
        res = "OK"

    conn.commit()
    conn.close()

    return res




def populate(request):

    result = result_query("ex08/resources/planets.csv", "ex08_planets",
                        ('name', 'climate', 'diameter', 'orbital_period', 'population', 'rotation_period',
                        'surface_water', 'terrain'))

    result += '\n' + result_query("ex08/resources/people.csv", "ex08_people",
                        ('name', 'birth_year', 'gender', 'eye_color', 'hair_color', 'height',
                        'mass', 'homeworld'))

    return HttpResponse(result)





def ft_display():

    query = """SELECT people.name, people.homeworld, planets.climate  
    FROM ex08_people AS people
    JOIN ex08_planets AS planets ON (people.homeworld = planets.name)
    WHERE planets.CLIMATE LIKE '%windy%'
    ORDER BY people.name
    """

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
            result = response

    return result


def display(request):
    result = ft_display()
    if type(result) == str:
        return HttpResponse(result)

    return render(request, "ex08_display.html", {'result':result})
