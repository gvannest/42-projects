import sys


def get_coor(sum_ascii):

    if sum_ascii % 2 == 0:
        latitude = sum_ascii % 90 / 1.0000001
        longitude = sum_ascii % -180 / 1.0000001

    else:
        latitude = sum_ascii % -90 / 1.0000001
        longitude = sum_ascii % 180 / 1.0000001

    return "({:.6f}, {:.6f})".format(latitude, longitude)




def geohashing(list_args):

    sum_ascii = 0
    for e in list_args:
        for c in e:
            sum_ascii += ord(c)

    coor = get_coor(sum_ascii)

    print(coor)

    return None


if __name__ == '__main__':
    if len(sys.argv) > 1:
        geohashing(sys.argv)
    else:
        print("If you don't provide arguments, you'll have to go to the Earth's center ahahaha!")