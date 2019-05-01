import argparse, ipdb, pytest
from parsing import process_file
from objects import Taquin
from tests import test_this_shit
from termcolor import cprint, colored
from npuzzle_solver import main as solve
import random
from integrity import is_solvable

def generator(size):
    while True:
        buff = [x for x in range(size**2)]
        random.shuffle(buff)
        grid = [buff[i:i+size] for i in range(0, len(buff), size)]
        if is_solvable(grid, size):
            break
    return buff

def main():
    parser = argparse.ArgumentParser(description="N-puzzle Solver")
    parser.add_argument('-f', '--filename', type=str, help="Put a '.txt' file containing a puzzle to solve")
    parser.add_argument('-t', '--test', action='store_true')
    parser.add_argument('-g', '--generator', type=int, help="if the '--generator' flag is present, it must be followed by an int and optionnaly by the flag '-u' if you want a unsolvable puzzle")

    args = parser.parse_args()
    if args.test:
        test_this_shit()
    if args.filename:
        t = process_file(args.filename)
        cprint("File processed successfully", 'green')
        grid = [x for y in t.g for x in y]
    elif args.generator:
        grid = generator(args.generator)
        cprint("Grid generated", 'green')

    cprint("Trying to solve...", 'green')
    solve(grid) 

if __name__ == '__main__':
    main()
