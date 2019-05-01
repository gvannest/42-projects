import copy

def get_xy(pos, size):
    x = int(pos % size)
    y = int(pos / size)
    return x, y

def create_success_grid(grid_size):
    """
        return the grid solution of the puzzle
        The grid is like [x, x, x],
                         [x, x, x],
                         [x, x, x] ... 
    """
    l = []
    for x in range(grid_size):
        l.append(['']*grid_size)
    pos = 0
    size = grid_size
    buff = [x for x in range(1, size**2)]
    buff.append(0)
    x, y = get_xy(pos, size)
    while buff:
        while x + 1 < size and l[y][x] == '':
            l[y][x] = buff.pop(0)
            pos +=1
            x, y = get_xy(pos, size)
            if x + 1 < size and l[y][x+1] != '':
                break
        
        while y + 1 < size and l[y][x] == '':
            l[y][x] = buff.pop(0)
            pos += size
            x, y = get_xy(pos, size)
            if y + 1 < size and l[y + 1][x] != '':
                break

        while x - 1 >= 0 and l[y][x] == '':
            l[y][x] = buff.pop(0)
            pos -= 1
            x, y = get_xy(pos, size)
            if x - 1 >=0 and l[y][x-1] != '':
                break

        while y - 1 >= 0 and l[y][x] == '':
            l[y][x] = buff.pop(0)
            pos -= size
            x, y = get_xy(pos, size)
            if y - 1 >= 0 and l[y - 1][x] != '':
                break

    return l

def grid_to_snail(grid, grid_size):
    l = copy.deepcopy(grid)
    pos = 0
    size = grid_size
    buff = []
    x, y = get_xy(pos, size)
    while len(buff) != size**2:
        while x + 1 < size and l[y][x+1] != '':
            buff.append(l[y][x])
            l[y][x] = ''
            pos +=1
            x, y = get_xy(pos, size)
            if x + 1 < size and l[y][x+1] == '':
                break

        while y + 1 < size and l[y+1][x] != '':
            buff.append(l[y][x])
            l[y][x] = ''
            pos += size
            x, y = get_xy(pos, size)
            if y + 1 < size and l[y + 1][x] == '':
                break

        while x - 1 >= 0 and l[y][x - 1] != '':
            buff.append(l[y][x])
            l[y][x] = ''
            pos -= 1
            x, y = get_xy(pos, size)
            if x - 1 >=0 and l[y][x-1] == '':
                break

        while y - 1 >= 0:
            buff.append(l[y][x])
            l[y][x] = ''
            pos -= size
            x, y = get_xy(pos, size)
            if y - 1 >= 0 and l[y - 1][x] == '':
                break
    return buff
    
def main():
    l = [
        [1,   2,  3, 4],
        [12, 13, 14, 5],
        [11,  0, 15, 6],
        [10,  9,  8, 7],
    ]
    l2 = [
        [1,2,3],
        [8,0,4],
        [7,6,5]
    ]
    l3 = [
        [1, 2, 3, 4, 5],
        [16, 17, 18, 19,6],
        [15, 24, 0, 20,7],
        [14, 23, 22, 21,8],
        [13, 12, 11,10,9],
    ]
    l4 = [
        [ 1,  2,  3,  4,  5,  6],
        [20, 21, 22, 23, 24,  7],
        [19, 32, 33, 34, 25,  8],
        [18, 31,  0, 35, 26,  9],
        [17, 30, 29, 28, 27, 10],
        [16, 15, 14, 13, 12, 11],
    ]
    l5 = [

        [  1,  2,  3,  4,  5,  6, 7],
        [ 24, 25, 26, 27, 28, 29, 8],
        [ 23, 40, 41, 42, 43, 30, 9],
        [ 22, 39, 48,  0, 44, 31, 10],
        [ 21, 38, 47, 46, 45, 32, 11],
        [ 20, 37, 36, 35, 34, 33, 12],
        [ 19, 18, 17, 16, 15, 14, 13],
    ]
    snail_it(l2)
    snail_it(l)
    snail_it(l3)
    snail_it(l4)
    snail_it(l5)


if __name__ == '__main__':
    main()
