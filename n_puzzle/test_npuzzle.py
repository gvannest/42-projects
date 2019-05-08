from node_class import Node
from algo_class import Algo
import pytest

@pytest.fixture
def generate_nodes():
    Node.final_grid = [1,2,3,8,0,4,7,6,5]
    Node.size = 3
    Node.h_method = 'manhattan'
    astar = Algo()

    node0 = Node([3,1,5,7,2,6,8,0,4])
    node1 = Node(grid=[2,1,6,8,4,0,5,7,3], g=0)
    node2 = node1.move('down', astar)
    node3 = node1.move('left', astar)
    node4 = node3.move('up', astar)
    node5 = Node([7,0,5,1,6,3,8,2,4])
    node6 = Node([3,4,5,6,7,0,2,8,1])
    node7 = Node([0,2,1,3,8,7,6,5,4])
    node8 = Node([0,2,1,7,8,5,6,3,4])
    node9 = Node([4,3,6,2,1,8,5,7,0])
    node10 = Node([2,7,0,1,6,5,8,3,4])
    node11 = Node([0,2,3,8,1,5,7,6,4])
    return [node0, node1, node2, node3, node4, node5, node6,
            node7, node8, node9, node10, node11]


def test_manhattan_heuristic(generate_nodes):
    assert generate_nodes[0].h_calc('manhattan') == 11
    assert generate_nodes[1].h_calc('manhattan') == 11
    assert generate_nodes[2].h_calc('manhattan') == 10
    assert generate_nodes[3].h_calc('manhattan') == 10
    assert generate_nodes[4].h_calc('manhattan') == 11
    assert generate_nodes[5].h_calc('manhattan') == 11
    assert generate_nodes[6].h_calc('manhattan') == 19
    assert generate_nodes[7].h_calc('manhattan') == 12
    assert generate_nodes[8].h_calc('manhattan') == 10
    assert generate_nodes[9].h_calc('manhattan') == 16
    assert generate_nodes[10].h_calc('manhattan') == 12


def test_lc_heuristic(generate_nodes):
    assert generate_nodes[0].h_calc('linear_conflict') == 17
    assert generate_nodes[1].h_calc('linear_conflict') == 15
    assert generate_nodes[2].h_calc('linear_conflict') == 14
    assert generate_nodes[3].h_calc('linear_conflict') == 16
    assert generate_nodes[4].h_calc('linear_conflict') == 15
    assert generate_nodes[5].h_calc('linear_conflict') == 21
    assert generate_nodes[6].h_calc('linear_conflict') == 19
    assert generate_nodes[7].h_calc('linear_conflict') == 14
    assert generate_nodes[8].h_calc('linear_conflict') == 14
    assert generate_nodes[9].h_calc('linear_conflict') == 18
    assert generate_nodes[10].h_calc('linear_conflict') == 14


def test_misplaced(generate_nodes):
    assert generate_nodes[0].h_calc('misplaced_tiles') == 8
    assert generate_nodes[1].h_calc('misplaced_tiles') == 7
    assert generate_nodes[2].h_calc('misplaced_tiles') == 7
    assert generate_nodes[3].h_calc('misplaced_tiles') == 6
    assert generate_nodes[4].h_calc('misplaced_tiles') == 6
    assert generate_nodes[5].h_calc('misplaced_tiles') == 8
    assert generate_nodes[6].h_calc('misplaced_tiles') == 8
    assert generate_nodes[7].h_calc('misplaced_tiles') == 7
    assert generate_nodes[8].h_calc('misplaced_tiles') == 7
    assert generate_nodes[9].h_calc('misplaced_tiles') == 8
    assert generate_nodes[10].h_calc('misplaced_tiles') == 8
    assert generate_nodes[11].h_calc('misplaced_tiles') == 3