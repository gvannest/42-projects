import psycopg2


def connection_db():
    conn = psycopg2.connect(
        database='formationdjango',
        host='localhost',
        user='djangouser',
        password='secret',
    )
    return conn



def query_create_table(table):
    query = """ CREATE TABLE IF NOT EXISTS {} (
            title varchar(64) UNIQUE NOT NULL,
            episode_nb int PRIMARY KEY,
            opening_crawl TEXT,
            director varchar(32) NOT NULL,
            producer varchar(128) NOT NULL,
            release_date date NOT NULL
            )
            """.format(table)
    return query



def result_query_execute(query):
    try:
        conn = connection_db()
        curr = conn.cursor()
        curr.execute(query)
    except Exception as e:
        print(e)
        res = e
    else:
        res = "OK"

    conn.commit()
    conn.close()

    return res



