import pickle, requests, random
from django.conf import settings
from .Movie import Movie


def get_rating(rating):
    for item in rating:
        if item['Source'] == 'Internet Movie Database':
            return item['Value']


def query(title):
    api_key = '94578c04'
    params = {'apiKey': api_key, 't': title}
    data_url = "http://www.omdbapi.com"
    r = requests.get(data_url, params=params)
    if r.status_code >= 400:
        raise Exception("Request error, code {}".format(r.status_code))
    data = r.json()
    IMDB_rating = get_rating(data['Ratings'])
    movie = Movie(data['Title'].lower(), data['Year'], IMDB_rating, data['Plot'], data['Actors'], data['Poster'], data['Director'])
    return movie


class GameManager:
    def __init__(self):
        self.data = {}

    def __str__(self):
        str = ""
        for key, value in self.data['moviemons'].items():
            str += key + ", "
        return "POSITION --> {}\n MOVIEBALLS --> {}\nMOVIEDEX --> {}\nMOVIEMONS --> [{}]\n".format(self.data['player_position'], self.data['movieballs'], self.data['moviedex'], str)

    def load(self, file_name):
        with open(file_name, 'rb') as file:
            self.data = pickle.load(file)
            return self

    def dump(self, filename):
        with open(filename, 'wb') as file:
            pickle.dump(self.data, file)

    def get_random_movie(self):
        if len(list(self.data['moviemons'].keys())) == len(self.data['moviedex']):
            return None
        movie = random.choice(list(self.data['moviemons'].keys()))
        while movie in self.data['moviedex']:
            movie = random.choice(list(self.data['moviemons'].keys()))
        return movie

    def load_default_settings(self):
        moviemons = {}
        for movie in settings.FILMS:
            moviemons[query(movie).title] = query(movie)
        self.data = {
            'player_position': settings.STARTING_POSITION,
            'movieballs': 0,
            'moviedex': [],
            'moviemons': moviemons
        }
        return self

    def get_strength(self):
        return len(self.data['moviedex'])

    def get_movie(self, title):
        if title not in list(self.data['moviemons'].keys()):
            return None
        m = self.data['moviemons'][title]
        return {
            'title': m.title,
            'year': m.year,
            'rating': m.rating,
            'summary': m.summary,
            'actors': m.actors,
            'poster': m.poster,
            'director': m.director
        }

    def get_chance(self, title):
        m = self.data['moviemons'][title]
        enemy_strength = float(m.rating.split('/')[0])
        chance = 50 - (enemy_strength * 10) + (self.get_strength() * 5)
        if chance < 1:
            return 1
        elif chance > 90:
            return 90
        return chance
