import sys

def parsing(lines):

    dict_elements = {}
    for e in lines:
        e_split = e.split("=")
        dict_elements[e_split[0].strip()] = e_split[1].split(',')

    for k,v in dict_elements.items():
        dict_single = {}
        for e in v:
            e_split = e.split(":")
            dict_single[e_split[0].strip()] = e_split[1].strip()
        dict_single['nb_electron'] = len(dict_single['electron'].split())
        dict_elements[k] = dict_single

    return dict_elements


def table_header(table_html):

        header = '<!DOCTYPE html>\n<html lang="en">\n\t<head>\n'+\
                '\t\t<meta charset="UTF-8">\n\t\t<title>periodic_table</title>\n'+\
                '\t</head>\n\t<body>\n\t\t<table>\n'

        table_html.write(header)

        return None


def create_case(dict_elements):

    for k,v in dict_elements.items():
        string = '\t\t\t\t<td style="border: 1px solid black; padding:10px">\n'+\
                '\t\t\t\t\t<h4>{0}</h4>\n'.format(k)+\
                '\t\t\t\t\t<ul>\n'+\
                '\t\t\t\t\t\t<li>No {0}</li>\n'.format(v['number']) +\
                '\t\t\t\t\t\t<li>{0}</li>\n'.format(v['small']) +\
                '\t\t\t\t\t\t<li>{0}</li>\n'.format(v['molar']) +\
                '\t\t\t\t\t</ul>\n'+\
                '\t\t\t\t</td>\n'
        dict_elements[k]['html'] = string

    return None


def create_row(table_html, dict_elements, i, j):

    for k,v in dict_elements.items():
        if v['nb_electron'] == i + 1 and int(v['position']) == j:
            return v['html']

    return None


def build_string(table_html, dict_elements):

    for i in range(7):
        string = '\t\t\t<tr>\n'
        for j in range(18):
            temp = create_row(table_html, dict_elements, i, j)
            if temp:
                string = string + temp
            else:
                string = string + '\t\t\t\t<td style="border: 1px solid black"></td>\n'
        string = string + '\t\t\t</tr>\n'
        table_html.write(string)
    return None

def main(argv1):

    with open(argv1, 'r') as f:
        list_lines = f.readlines()

    dict_elements = parsing(list_lines)

    with open('./periodic_table.html', 'w') as table_html:
        table_header(table_html)
        create_case(dict_elements)
        build_string(table_html, dict_elements)
        table_html.write('\t\t</table>\n' + '\t</body>\n' + '</html>')

    return None 

if __name__ == "__main__":
    if len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        print("Pas de fichier joint.")
