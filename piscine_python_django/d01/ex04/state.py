import sys

def main_cities(city):

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

    if city not in capital_cities.values():
        return "Unknown city"
    else:
        state = [k for k,v in states.items() if capital_cities[v] == city]
        return state[0]

def main():

    if len(sys.argv) == 2:
        city = sys.argv[1]
        print(main_cities(city))

    return None

if __name__ == "__main__":
    main()
