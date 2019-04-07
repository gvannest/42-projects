

def read_numbers():
    """Read a list of numbers and print it on standard output,
    one by line and without comma
    """

    path = "./numbers.txt"
    with open(path, 'r') as f:
        numbers_list = f.read()[:-1].split(',')

    for n in numbers_list:
        print(n)

    return None


if __name__ == "__main__":
    read_numbers()
