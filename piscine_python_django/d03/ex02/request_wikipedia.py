import requests
import json
import sys
from dewiki.parser import Parser



def requete(search_string):

    S = requests.Session()

    URL = "https://en.wikipedia.org/w/api.php"
    PARAMS_PAGE = {
        'action': "query",
        'list': "search",
        'srsearch': search_string,
        'format': "json"
    }

    result = S.get(url=URL, params=PARAMS_PAGE)
    data = result.json()

    if int(data['query']['searchinfo']['totalhits']) == 0:
        print("No matches found. Try another query")
        return None

    page_id = data['query']['search'][0]['pageid']

    PARAMS_ID = {
        'action': "parse",
        'pageid': page_id,
        'format': "json",
        'prop': "wikitext",
    }

    result_page = S.get(url=URL, params=PARAMS_ID)
    data_page = result_page.json()
    text = data_page['parse']['wikitext']['*']
    text_parse = Parser().parse_string(text)

    with open("{}.wiki".format(search_string), 'w') as file:
        file.write(text_parse)

    return None

if __name__ == '__main__':
    if len(sys.argv) == 2:
        try:
            requete(sys.argv[1].strip())
        except Exception as e:
            print(e)
    else:
        print("One and only one search query should be provided")