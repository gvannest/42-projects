class Node:
    """
    Class which represents a node of our graph, i.e a state of the n-puzzle grid.

    Class attributes:
        final_grid (list[int]):  The grid representing the final node (the objective)
        size (int): The size of of the n-puzzle
        h_method: the heuristic method chosen

    Object attributes:
        grid (list[int]): Current state of the puzzle; i.e. state of the grid at current node
        h (int) : value of heuristic at the current node
        g (int): sum of past movement costs since the starting node
        parent (Node) : node from which the current node originates
    """

    final_grid = []
    size = 0
    h_method = None
    h_algo = None

    def __init__(self, grid, chg_i=None, g=0, parent=None):
        self.grid = grid
        self.parent = parent
        self.chg_i = chg_i
        self.conflict = 0
        self.h = self.h_calc(Node.h_method) if Node.h_algo != 'uniformed_cost' else 0
        self.g = g if Node.h_algo != 'GBFS' else 0
        self.f = self.h + self.g

    def is_final(self):
        """Method which returns True if self is the final node"""
        return self.grid == Node.final_grid

    def h_calc(self, method):
        """
        Method which calculates the heuristic for each node.

        Parameters:
            method (str): The heuristic method used to calculate the heuristic distance. To be chosen between:
                            * manhattan:    sum of distances between each current number position and its final
                                            position. Distance is the number of verticla or horizontal moves.

        Returns:
            Value of the heuristic of the current node
        """

        def misplaced_tiles():
            """Calculate the number of tiles which are misplaced on the current grid"""
            tiles = 0
            for c,f in zip(self.grid, Node.final_grid):
                if c:
                    if c - f:
                        tiles += 1
            return tiles


        def manhattan_distance(c_idx, f_idx):
            """ Calculate the Manhattan distance between current and final position"""
            f_pos = (f_idx // Node.size, f_idx % Node.size)
            c_pos = (c_idx // Node.size, c_idx % Node.size)
            return abs(c_pos[0] - f_pos[0]) + abs(c_pos[1] - f_pos[1])

        def manhattan_heuristic():
            """Calculate the heuristic based on Manhattan distance"""
            h = 0
            if self.parent:
                f_idx = Node.final_grid.index(self.grid[self.chg_i['current']])
                h = self.parent.h + (manhattan_distance(self.chg_i['current'], f_idx) -
                                     manhattan_distance(self.chg_i['previous'], f_idx))
            else:
                for c_idx, c in enumerate(self.grid):
                    if c != 0:
                        f_idx = Node.final_grid.index(c)
                        h += manhattan_distance(c_idx, f_idx)
            return h

        def treat_conflict(curr_list, final_list):
            """Calculates the number of conflicts between two lists, excluding 0"""
            nb_conflicts = 0
            c = curr_list[0]
            c_fidx = final_list.index(c)
            for e in curr_list[1:]:
                if e in final_list and e:
                    e_fidx = final_list.index(e)
                    if e_fidx - c_fidx < 0:
                        nb_conflicts += 1
            return nb_conflicts

        def linear_conflict():
            """
            Function which calculates the sum of manhattan distance and number of linear conflicts * 2.
            For each element in self.grid (current grid) : we treat its line and then its column, if the element
            is currently located on its final line / column.
            We buid two lists : one corresponding to the current line (or col) and one corresponding to the final
            line (or col). Then to treat conflicts we compare these two lists.

            :return: Manhattan + 2 * number of conflicts (which is our heuristic cost)
            """
            conflicts = 0
            for c_idx, c in enumerate(self.grid):
                if c != 0:
                    f_idx = Node.final_grid.index(c)

                    if c_idx // Node.size == f_idx // Node.size and c_idx % Node.size != (Node.size - 1):
                        i = c_idx
                        curr_ln = []
                        while i // Node.size == c_idx // Node.size: # tant qu'on est sur la meme ligne
                            curr_ln.append(self.grid[i])
                            i += 1
                        i = (f_idx // Node.size) * Node.size
                        final_ln = []
                        while i // Node.size == c_idx // Node.size:
                            final_ln.append(Node.final_grid[i])
                            i += 1
                        conflicts += treat_conflict(curr_ln, final_ln)

                    if c_idx % Node.size == f_idx % Node.size and c_idx // Node.size != (Node.size - 1):
                        i = c_idx
                        curr_col = [c]
                        while i < Node.size ** 2:
                            curr_col.append(self.grid[i])
                            i += Node.size
                        i = (f_idx % Node.size)
                        final_col = []
                        while i < Node.size ** 2:
                            final_col.append(Node.final_grid[i])
                            i += Node.size
                        conflicts += treat_conflict(curr_col, final_col)

            return manhattan_heuristic() + 2 * conflicts

        dic_h = {
            'manhattan': manhattan_heuristic,
            'linear_conflict': linear_conflict,
            'misplaced_tiles': misplaced_tiles,
        }

        return dic_h[method]()

    def move(self, direction, astar):
        """
        The function to swap the blank square with its neighbours in the four possible directions.

        Parameters:
            direction (str): down, up, left or right

        Returns:
            A new node, son of current node, which grid attributes is the new grid following the swap
            of the blank square with its neighbour in the chosen direction.
            None if swapping positions in the chosen direction is impossible.
        """

        idx_blank = self.grid.index(0)
        blank_pos = (idx_blank // Node.size, idx_blank % Node.size)

        def move_down(blank_pos):
            if blank_pos[0] < Node.size - 1:
                return (blank_pos[0] + 1, blank_pos[1])

        def move_up(blank_pos):
            if blank_pos[0] > 0:
                return (blank_pos[0] - 1, blank_pos[1])

        def move_left(blank_pos):
            if blank_pos[1] > 0:
                return (blank_pos[0], blank_pos[1] - 1)

        def move_right(blank_pos):
            if blank_pos[1] < Node.size - 1:
                return (blank_pos[0], blank_pos[1] + 1)

        dic_move = {
            'down': move_down,
            'up': move_up,
            'left': move_left,
            'right': move_right,
        }

        new_blank_pos = dic_move[direction](blank_pos)

        if not new_blank_pos:
            return None

        new_grid = self.grid[:]
        new_idx_blank = new_blank_pos[0] * Node.size + new_blank_pos[1]
        new_grid[idx_blank], new_grid[new_idx_blank] = new_grid[new_idx_blank], new_grid[idx_blank]

        if tuple(new_grid) not in astar.closed_set:
            new_node = Node(new_grid, chg_i={'current': idx_blank, 'previous': new_idx_blank}, g=(self.g + 1), parent=self)
        else:
            new_node = None

        return new_node

    def __str__(self):
        """Overrides __str__ method such that we have the snail representation of the self.grid when printing a node"""
        result = ''
        for i, n in enumerate(self.grid):
            result += str(n)
            if i != 0 and (i + 1) % self.size == 0:
                result += '\n'
            elif n > 9:
                result += ' '
            else:
                result += 2 * ' '
        return result

    def __eq__(self, other):
        return self.h + self.g == other.h + other.g

    def __ne__(self, other):
        return self.h + self.g != other.h + other.g

    def __gt__(self, other):
        if self.__eq__(other):
            if self.h == other.h:
                return self.g > other.g
            return self.h > other.h
        return self.h + self.g > other.h + other.g

    def __ge__(self, other):
        if self.__eq__(other):
            if self.h == other.h:
                return self.g >= other.g
            return self.h >= other.h
        return self.h + self.g >= other.h + other.g

    def __lt__(self, other):
        if self.__eq__(other):
            if self.h == other.h:
                return self.g < other.g
            return self.h < other.h
        return self.h + self.g < other.h + other.g

    def __le__(self, other):
        if self.__eq__(other):
            if self.h == other.h:
                return self.g <= other.g
            return self.h <= other.h
        return self.h + self.g <= other.h + other.g
