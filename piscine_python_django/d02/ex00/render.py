
import sys
import os
import re

def start_html(kwargs):
    """Start the html file with doctype, html, head, title, body"""

    header = '<!DOCTYPE html>\n<html lang="en">\n<head>\n'+\
            '<meta charset="UTF-8">\n<title>CV '+kwargs['firstname']+' '+\
            kwargs['name']+'</title>\n</head>\n<body>\n'

    return header

def building_string(template_str, dic_settings):

    string = start_html(dic_settings)
    try:
       string += template_str.format(**dic_settings)
    except Exception as e:
        print(e)
        sys.exit(0)
 
    string += '</body>\n' + '</html>'

    return string


def main(arg1):

    with open(arg1, 'r') as template:
        template_str = template.read()

    list_settings = [a for a in dir(settings) if not a.startswith('__')]
    dic_settings = {}
    for key in list_settings:
        dic_settings[key] = getattr(settings, key)

    with open("./cv.html", 'w') as cv_html:
        cv_html.write(building_string(template_str, dic_settings))

    return None


if __name__ == "__main__":

    
    try:
        import settings
        if len(sys.argv) != 2:
            raise ValueError("Wrong number of arguments")
        if not os.path.isfile(sys.argv[1]):
            raise FileNotFoundError("File does not exist.")
        if not sys.argv[1].endswith('.template'):
            raise NameError("Wrong file extension.")
    except ImportError as i:
        print("ImportError : module 'settings' cannot be found")
    except (ValueError, FileNotFoundError, NameError)  as e:
        print(type(e).__name__+' : '+e.__str__())
    else:
        main(sys.argv[1])
