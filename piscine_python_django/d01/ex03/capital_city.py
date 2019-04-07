import sys

def main_cities(state):

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

    if state not in states.keys():
        return "Unknown state"
    else:
        return capital_cities[states[state]]

def main():

    if len(sys.argv) == 2:
        state = sys.argv[1]
        print(main_cities(state))

    return None

if __name__ == "__main__":
    main()
