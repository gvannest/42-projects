from django.shortcuts import render, HttpResponse
from django.conf import settings
from pathlib import Path
from os import listdir, path, remove
import random, re
from .Controls import Controls
from .GameManager import GameManager


def title_screen(request):
    controls = Controls(a='worldmap/', b='load_game')
    return render(request, "movieMon/title_screen.html", {'controls': controls})


def get_up(x, y):
    if y == 0:
        return x, y
    else:
        return x, y - 1


def new_position_is_possible(old_player_position, new_x, new_y):
    if new_x < 0 or new_x >= settings.GRID_SIZE[0] or new_y < 0 or new_y >= settings.GRID_SIZE[1]:
        return False
    (x, y) = old_player_position
    if (new_x, new_y) == (x, y - 1) or \
            (new_x, new_y) == (x, y + 1) or \
            (new_x, new_y) == (x + 1, y) or \
            (new_x, new_y) == (x - 1, y) or \
            (new_x, new_y) == (x, y):
        return True


def get_game():
    game_info = Path('game_info.mmg')

    if game_info.is_file():
        game_info.chmod(0o777)
        game = GameManager().load('game_info.mmg')
    else:
        game = GameManager().load_default_settings()
    return game


def get_position(req):
    game = get_game()
    old_player_position = game.data['player_position']
    new_position = req.POST.get('position', None)
    try:
        new_position = new_position.strip('(').strip(')').replace(" ", "").split(',')
        [new_x, new_y] = (int(new_position[0]), int(new_position[1]))
    except (TypeError, AttributeError):
        player_position = old_player_position
    else:
        if new_position_is_possible(old_player_position, new_x, new_y):
            player_position = (new_x, new_y)
        else:
            player_position = old_player_position
    return game, player_position, old_player_position


def world_map(request):
    grid_size = settings.GRID_SIZE

    (game, player_position, old_player_position) = get_position(request)
    (x, y) = player_position
    game.data['player_position'] = player_position
    bottom_message = ["SELECT --- Moviedex", "START --- Options"]
    matrix = []
    for row in range(grid_size[1]):
        matrix.append([])
        for column in range(grid_size[0]):
            if (column, row) == player_position:
                matrix[row].append('P')
            else:
                matrix[row].append(0)

    controls = Controls()
    controls.up = (x, y - 1) if y != 0 else (x, y)
    controls.down = (x, y + 1) if y != grid_size[1] - 1 else (x, y)
    controls.right = (x + 1, y) if x != grid_size[0] - 1 else (x, y)
    controls.left = (x - 1, y) if x != 0 else (x, y)
    controls.start = 'options/'
    controls.select = 'moviedex/'
    top_message = ["MOVIEBALLS: {}".format(game.data['movieballs'])]

    r = random.randint(1, 8)
    if r == 1 and old_player_position != player_position:
        game.data['movieballs'] += 1
        bottom_message = ["YEY! You found a new Movieball!"]
    elif r == 2 and old_player_position != player_position:
        new_moviemon = game.get_random_movie()
        if new_moviemon:
            controls.a = "battle/{}/".format(new_moviemon.replace(" ", "_"))
            bottom_message = ["You found {}".format(new_moviemon.upper()),
                              "Press A to fight it, START to go to Options, SELECT to check your Moviedex".format(
                                  new_moviemon.upper())]

    game.dump("game_info.mmg")

    return render(request, "movieMon/worldmap.html",
                  {'controls': controls, 'matrix': matrix, 'top_message': top_message,
                   'bottom_message': bottom_message, 'form_action': '/worldmap'})


def battle(request, title):
    game = GameManager().load("game_info.mmg")
    movie = game.get_movie(title.replace("_", " "))
    chances = int(game.get_chance(title.replace("_", " ")))
    if not movie:
        return HttpResponse("Are you trying to cheat?")

    controls = Controls(b='worldmap/')

    bottom_message = ["B --- go back to Worldmap"]
    response = ""

    launched = request.POST.get('value', None)
    if launched == 'launched':
        if game.data['movieballs'] == 0:
            response = " HA HA loser "
        else:
            game.data['movieballs'] -= 1

            array = [True] * chances + [False] * (100 - chances)
            success = random.choice(array)
            response = " CAPTURED! " if success else " YOU MISSED! "
            if not success:
                bottom_message = ["A --- launch Movieball!"] + bottom_message
                controls.a = "battle/{}?launched=True".format(title)
            else:
                game.data['moviedex'].append(title.replace("_", " "))
    else:
        controls.a = "launched"
        bottom_message = ["A --- launch Movieball!"] + bottom_message

    top_message = ["MOVIEBALLS: {}".format(game.data['movieballs']), "STRENGTH: {}".format(game.get_strength()),
                   "CHANCES OF CAPTURE: {}%".format(chances)]
    game.dump("game_info.mmg")
    return render(request, "movieMon/battle.html",
                  {'controls': controls, 'top_message': top_message, 'bottom_message': bottom_message, 'movie': movie,
                   'response': response, 'a_form': 'battle/{}'.format(title)})


def moviedex(request):
    game = get_game()
    controls = Controls(select='worldmap/')
    top_message = ["MOVIEDEX"]
    bottom_message = ["A --- more information", "SELECT --- go back "]
    moviedex = list(map(lambda x: game.data['moviemons'][x], game.data['moviedex']))

    new_position = request.POST.get('position')
    try:
        new_position = new_position.strip('(').strip(')').replace(" ", "").split(',')
        [new_x, new_y] = (int(new_position[0]), int(new_position[1]))
    except (TypeError, AttributeError):
        selected = (0, 0)
    else:
        selected = (new_x, new_y)

    res = []
    (x, y) = selected
    for i in range(len(moviedex) // 4 + 1):
        res.append([])
        for c in range(4):
            if i * 4 + c < len(moviedex):
                css_class = 'moviedex_poster_active' if selected == (c, i) else 'moviedex_poster'
                res[i].append(
                    {'poster': moviedex[i * 4 + c].poster, 'class': css_class, 'title': moviedex[i * 4 + c].title})

    controls.up = (x, y - 1) if y != 0 else (x, y)
    controls.down = (x, y + 1) if (y + 1 < len(res)) and x < len(res[y + 1]) else (x, y)
    controls.right = (x + 1, y) if x != 3 and x + 1 < len(res[y]) else (x, y)
    controls.left = (x - 1, y) if x != 0 else (x, y)

    controls.a = 'moviedex/{}'.format(res[y][x]['title'].replace(" ", "_"))

    return render(request, "movieMon/moviedex.html",
                  {'controls': controls, 'top_message': top_message, 'bottom_message': bottom_message,
                   'posters': moviedex, 'lines': res, 'form_action': '/moviedex'})


def details(request, title):
    game = get_game()
    title = title.replace("_", " ")

    info = game.data['moviemons'][title]
    bottom_message = ["B --- go back "]
    top_message = [title.upper()]
    controls = Controls(b='moviedex/')

    return render(request, "movieMon/details.html",
                  {'controls': controls, 'top_message': top_message, 'bottom_message': bottom_message, 'movie': info})


def options(request):
    controls = Controls(a="save_game/", b="", start="worldmap/")
    return render(request, "movieMon/options.html", {'controls': controls})

def is_valid_filename(filename):
    pattern = re.compile("^slot[abc]_\d+_\d+.mmg$")
    return pattern.match(filename)

def get_slot_table():

    dir = Path('./saved_game')
    if not dir.is_dir():
        dir.mkdir()
    files = list(filter(is_valid_filename, [f for f in listdir(dir) if path.isfile(path.join(dir, f))]))
    array_slot = [{'arrow': '', 'name': 'Slot A', 'info': 'Free'},
                  {'arrow': '', 'name': 'Slot B', 'info': 'Free'},
                  {'arrow': '', 'name': 'Slot C', 'info': 'Free'}]
    for slot_path in files:
        filename = path.join(dir, slot_path)
        index = ord(slot_path[4]) - ord('a')
        game = Path(filename)
        game.chmod(0o777)
        game = GameManager().load(filename)
        array_slot[index]['info'] = "{}/{}".format(len(game.data['moviedex']), len(game.data['moviemons']))
    return array_slot


def save(request):
    dir = Path('./saved_game')
    position = int(request.POST.get('position', 0))
    saved = request.POST.get('value', None)
    top_message = []
    bottom_message = ["A --- Save", "B --- Cancel"]
    if saved:
        position = int(saved)
        lst = list(filter(lambda x: str(chr(position + 97)) in x, (list(filter(is_valid_filename, [f for f in listdir(dir) if path.isfile(path.join(dir, f))])))))
        if len(lst) > 0:
            existing_file = lst[0]
            remove("{}/{}".format(dir, existing_file))
        top_message = ["Game saved on Slot {}".format(str(chr(position + 97)).upper())]
        game = GameManager().load("game_info.mmg")
        score = "{}_{}".format(len(game.data['moviedex']), len(game.data['moviemons']))
        game.dump("saved_game/slot{}_{}.mmg".format(str(chr(position + 97)), score))

    array_slot = get_slot_table()
    array_slot[position]['arrow'] = "-->"

    controls = Controls(a=position, b='options/', up=position - 1 if position > 0 else 0, down=position + 1 if position < 2 else 2)
    return render(request, "movieMon/saved_game.html",
                  {'table': array_slot, 'bottom_message': bottom_message, 'top_message': top_message,'controls': controls,
                   'form_action': '/save_game'})


def load(request):

    bottom_message = ["A --- Load", "B --- Cancel"]
    position = int(request.POST.get('position', 0))
    game_to_load = request.POST.get('value', None)
    array_slot = get_slot_table()
    a = None
    top_message = []
    if game_to_load:
        game_to_load = int(game_to_load)
        position = int(game_to_load)
        if array_slot[game_to_load]['info'] == 'Free':
            top_message = ["EMPTY SLOT!"]
        else:
            score = array_slot[position]['info'].split("/")
            filename = "saved_game/slot{}_{}_{}.mmg".format(str(chr(position + 97)), score[0], score[1])
            game = GameManager().load(filename)
            game.dump("game_info.mmg")
            a = 'worldmap/'
            top_message = ["GAME {} LOADED".format(str(chr(position + 97)).upper())]
            bottom_message[0] = "A --- Start game"

    array_slot[position]['arrow'] = "-->"
    controls = Controls(b='', a=position if not a else a, up=position - 1 if position > 0 else 0, down=position + 1 if position < 2 else 2)
    return render(request, "movieMon/load.html",
                  {'table': array_slot, 'bottom_message': bottom_message, 'controls': controls, 'top_message': top_message,
                   'form_action': '/load_game'})
