import sys
from objects import Taquin
from snailer import create_success_grid, grid_to_snail
from termcolor import colored

def error_handling(e):
    print(colored(e, 'red'))
    sys.exit(0)
    
def is_solvable(grid, grid_size):
    inv = 0
    flat_grid = grid_to_snail(grid, grid_size)
    for idx, x in enumerate(flat_grid):
        i = idx + 1
        if x == 0:
            blank_on_odd = (grid_size - int(idx / grid_size)) % 2
            continue
        while i < len(flat_grid):
            if x > flat_grid[i] and flat_grid[i] != 0:
                inv += 1
            i += 1
    return (grid_size % 2 == 1 and inv % 2 == 0) or (grid_size % 2 == 0 and blank_on_odd == inv % 2)

def check_integrity(numbers):
    t = Taquin()
    t.size = numbers.pop(0)
    if len(numbers) != len(set(numbers)):
        error_handling("[ERROR]: Duplicate values")
    if set(numbers) != set(range(t.size**2)):
        error_handling("[ERROR]: Weird number suite")
    t.g = [numbers[i:i+t.size] for i in range(0, len(numbers), t.size)]
    if not is_solvable(t.grid, t.size):
        error_handling("[ERROR]: Can't be done")
    t.success_grid = create_success_grid(t.size)
    return t
