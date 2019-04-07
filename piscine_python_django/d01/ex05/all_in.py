import sys

def find_place(list_places):

    states = {
            "Oregon" : "OR",
            "Alabama" : "AL",
            "New Jersey": "NJ",
            "Colorado" : "CO"
            }

    capital_cities = {
            "OR": "Salem",
            "AL": "Montgomery",
            "NJ": "Trenton",
            "CO": "Denver"
            }

    for place in list_places:
        place = " ".join(place.split())
        place_t = place.title()
        if place_t == '':
            pass
        elif place_t in states.keys():
            print("{} is the capital of {}".format(capital_cities[states[place_t]], place_t))
        elif place_t in capital_cities.values():
            state = [k for k,v in states.items() if capital_cities[v] == place_t]
            print("{} is the capital of {}".format(place_t, state[0]))
        else:
            print("{} is neither a capital city nor a state".format(place))

    return None


def main():

    if len(sys.argv) == 2:
        list_places = [e.strip() for e in sys.argv[1].split(',')]
        find_place(list_places)

    return None

if __name__ == "__main__":
    main()
