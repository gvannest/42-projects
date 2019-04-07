import requests
import sys
from bs4 import BeautifulSoup



def ft_request(query):

    S = requests.Session()

    result = S.get("https://en.wikipedia.org/wiki/{}".format(query))
    data = result.content

    return(BeautifulSoup(data, 'html.parser'))



def road_to_philosophy(query, list_titles):

    soup = ft_request(query)
    title = soup.html.body.find("h1", id="firstHeading").string

    if title in list_titles:
        return "It leads to an infinite loop !"
    list_titles.append(title)
    if title == 'Philosophy':
        return list_titles

    soup = soup.html.body.find("div", class_="mw-parser-output")

    try:
        soup.sup.extract()
        soup.table.extract()
    except Exception:
        pass

    soup_p2 = soup.find_all("p")

    link_url = []
    for p_tag in soup_p2:
        link_url.extend(p_tag.find_all("a"))

    link_final = []
    for e in link_url:
        if e.get('title') and 'Help' not in e.get('title') and "cite_note" not in e.get('href'):
            link_final.append(e)


    try:
        link = link_final[0].attrs['title']
    except Exception as e:
        return "It leads to a dead end man"
    else:
        to_return = road_to_philosophy(link, list_titles)

    return to_return

    return None


def launch_recursive(query):

    list_titles = []
    res = road_to_philosophy(query, list_titles)

    if type(res) == str:
        print(res)
    else:
        print("{0} roads from {1} to philosophy : {2}".format(len(res) - 1, query, res))

    return None

if __name__ == '__main__':
    if len(sys.argv) == 2:
        try:
            launch_recursive(sys.argv[1].strip().replace(' ','_'))
        except Exception as e:
            print(e)