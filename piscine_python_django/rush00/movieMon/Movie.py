
class Movie:
    def __init__(self, title, year, rating, summary, actors, poster, director):
        self.title = title
        self.year = year
        self.rating = rating
        self.summary = summary
        self.actors = actors
        self.poster = poster
        self.director = director

    def __str__(self):
        return "{}\n{}\n{}\n{}\n{}\n{}\n{}\n".format(self.title, self.year, self.director, self.summary, self.actors, self.rating, self.poster)

