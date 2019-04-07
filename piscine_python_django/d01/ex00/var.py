
def my_var():
    """Declare neuf variables et les imprime sur la sortie standard"""

    a = 42
    a_str = "42"
    a_verbose = "quarante_deux"
    a_float = 42.0
    a_bool = True
    a_list = [42]
    a_dict = {42: 42}
    a_tuple = (42,)
    a_set = set()

    print("{} est de type {}".format(a, type(a)))
    print("{} est de type {}".format(a_str, type(a_str)))
    print("{} est de type {}".format(a_verbose, type(a_verbose)))
    print("{} est de type {}".format(a_float, type(a_float)))
    print("{} est de type {}".format(a_bool, type(a_bool)))
    print("{} est de type {}".format(a_list, type(a_list)))
    print("{} est de type {}".format(a_dict, type(a_dict)))
    print("{} est de type {}".format(a_tuple, type(a_tuple)))
    print("{} est de type {}".format(a_set, type(a_set)))

    return None


if __name__ == "__main__":
    my_var()
