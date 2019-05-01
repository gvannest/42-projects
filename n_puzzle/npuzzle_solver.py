import argparse
from math import sqrt

from node_class import Node
from algo_class import Algo
from visu import Visu

def print_results(astar):
    """ Print the output of the search algorithm, including time and space complexity"""
    for node in astar.path:
        print(node)

    print("=======================")
    print('Number of moves from initial to final state :', len(astar.path) - 1)
    print("=======================")
    print('Time complexity (number of selected nodes) :', astar.selected_nodes)
    print("=======================")
    print('Space complexity (max states in memory at a point in time) :', astar.max_memory)

    return None


def search_algo(node, algo):
    """
    Function which implements our search algorithm.

    :param node: node which will be treated in this instance of the function
    :param algo: our search algorithm objects which stores relevant informations about the search process
    :return: none as the outcome of the search algorithm is in the algo object
    """

    directions = ['down', 'up', 'left', 'right']
    while not node.is_final():
        for d in directions:
            new_node = node.move(d, algo)
            if new_node:
                algo.push_to_heap(new_node)
        algo.closed_set.add(tuple(node.grid))
        node = algo.pop_from_heap()

    while node:
        algo.path.appendleft(node)
        node = node.parent
    return None


def parsing():
    parser = argparse.ArgumentParser()
    parser.add_argument('-m', '--method',
                        type=str,
                        choices=['manhattan', 'linear_conflict', 'misplaced_tiles'],
                        help="Method to be used for heuristic determination.",
                        default='misplaced_tiles')
    parser.add_argument('-a', '--algo',
                        type=str,
                        choices=['astar', 'GBFS', 'uniformed_cost'],
                        help="Algorithm used to solve the n-puzzle.",
                        default='uniformed_cost')
    parser.add_argument('-v', '--visu',
                        help="Show the results as an interactive game",
                        action='store_true')
    args = parser.parse_args()

    return args


def main(grid):

    args = parsing()

    grid_size = int(sqrt(len(grid)))
    Node.final_grid = [1,2,3,8,0,4,7,6,5]
    Node.size = grid_size
    Node.h_method = args.method
    Node.h_algo = args.algo

    initial_node = Node(grid=grid, g=0, parent=None)
    algo = Algo()
    search_algo(initial_node, algo)

    if args.visu:
        visu = Visu(algo)
        visu.play()
    else:
        print_results(algo)
    return None


if __name__ == "__main__":
    initial_grid = [3,1,5,7,2,6,8,0,4]
    main(initial_grid)
