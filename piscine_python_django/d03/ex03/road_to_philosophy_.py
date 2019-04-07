import requests
import sys
from bs4 import BeautifulSoup


def check_parenthesis(list_p):

    new_list_p = []
    for elem in list_p:
        new_elem = ''
        count_bracket = 0
        count_a = 0
        elem_str = str(elem)
        for i, c in enumerate(elem_str):
            if c == 'a' and elem_str[i - 1] == '<' and elem_str[i + 1] == ' ':
                count_a += 1
            if c == 'a' and elem_str[i - 1] == '/' and elem_str[i + 1] == '>':
                count_a -= 1
            if c == '(' and count_a == 0:
                count_bracket += 1
            if c == ')' and count_a == 0:
                count_bracket -= 1
            if count_bracket == 0:
                new_elem += c
        new_list_p.append(new_elem)

    return new_list_p



def road_to_philosophy(query, list_titles):

    S = requests.Session()

    result = S.get("https://en.wikipedia.org/wiki/{}".format(query))
    data = result.content

    soup = BeautifulSoup(data, 'html.parser')

    title = soup.html.body.find("h1", id="firstHeading").string

    if title in list_titles:
        return "It leads to an infinite loop !"
    list_titles.append(title)
    if title == 'Philosophy':
        return list_titles

    soup = soup.html.body.find("div", class_="mw-parser-output")

    try:
        soup.i.extract()
        soup.sup.extract()
        soup.table.extract()
    except Exception:
        pass

    soup_p = soup.find_all("p")

    list_p = check_parenthesis(soup_p)

    soup_p2 = []
    for e in list_p:
        soup_p2.append(BeautifulSoup(e, 'html.parser'))
    link_url = []
    for p_tag in soup_p2:
        link_url.extend(p_tag.find_all("a"))

    try:
        link = link_url[0].attrs['title']
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