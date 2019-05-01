import os
import ipdb
from integrity import *

def process_file(filename):
    numbers = parse_file(read_file(filename))
    return check_integrity(numbers)

def read_file(filename):
    data = ''
    if os.path.isfile(filename):
        try :
            with open(filename, 'r') as f:
                data = f.read()
            return data
        except Exception as e:
            error_handling(e)
    else:
        error_handling("[ERROR]: File does not exist. l2t")

def parse_file(data):
    lines = data.split('\n')
    numbers = []
    size = 0
    for line in lines:
        buff = ''
        for idx, char in enumerate(line): 
            if char == '#':
               break
            elif char == ' ':
                continue
            elif char.isdigit():
                buff += char
                if idx + 1 == len(line) or not line[idx + 1].isdigit():
                    numbers.append(int(buff))
                    buff = ''
            else:
                error_handling("[PARSING ERROR]: Found '{0}' line {2}: {1}".format(char, line, idx))
    return numbers
