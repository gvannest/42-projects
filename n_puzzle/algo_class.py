import heapq
from collections import deque

class Algo:
    """
    Class representing our A* algorithm.

    Attributes:

        opened_heap (heapq): the priority queue, storing the nodes to be visited, sorted according to their
                             estimated distance to the final node (g + h)

        closed_list (list[list]): list of already visited (and treated nodes). Nodes are all differents
                                    so we have to compare grids

        selected_nodes (int): Counter of nodes popped from the heap (i.e. treated). Starts at 1 as there is
                                at least the starting node. Indicative of time complexity

        memory_state (int): Counter of states ever represented in memory at the same time during the search.
                            Maximum is indicative of space complexity. Starts at 1 for the starting node

        max_memory (int): max memory_state at one point during the game

        path (list[Node]): result of the search algorithm; found path from start to end node.

    """

    def __init__(self):
        self.opened_heap = []
        self.closed_set = set()
        self.memory_state = 1
        self.selected_nodes = 1
        self.max_memory = 1
        self.path = deque()

    def push_to_heap(self, node):
        """Adding an node to our priority queue"""
        heapq.heappush(self.opened_heap, node)
        self.memory_state += 1
        if self.memory_state > self.max_memory:
            self.max_memory = self.memory_state
        return None

    def pop_from_heap(self):
        """Popping the first NON-VISITED node of our priority queue"""
        try:
            popped_node = heapq.heappop(self.opened_heap)
            while tuple(popped_node.grid) in self.closed_set:
                self.memory_state -= 1
                popped_node = heapq.heappop(self.opened_heap)
        except IndexError:
            return None
        else:
            self.selected_nodes += 1
            return popped_node


class Idastar(Algo):
    def __init__(self):
        super().__init__()

    def push_to_heap(self, node, opened_heap):
        """Adding an node to our priority queue"""
        heapq.heappush(opened_heap, node)
        self.memory_state += 1
        if self.memory_state > self.max_memory:
            self.max_memory = self.memory_state
        return None

    def pop_from_heap(self, opened_heap):
        """Popping the first NON-VISITED node of our priority queue"""
        try:
            popped_node = heapq.heappop(opened_heap)
            while tuple(popped_node.grid) in self.closed_set:
                self.memory_state -= 1
                popped_node = heapq.heappop(opened_heap)
        except IndexError:
            return None
        else:
            self.selected_nodes += 1
            return popped_node

    def clear(self):
        self.opened_heap = []
        self.closed_set = set()
        self.path = deque()
        self.memory_state = 1

