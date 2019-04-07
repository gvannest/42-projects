
import path.py


def test():

    path_dir = "./my_program_dir"
    path_file = "./{}/my_program_file.txt"

    dir = path.Path(path_dir)
    file = path.Path(path_file)
    if not dir.exists():
        dir.mkdir()
    if not file.exists():
        file.touch()
    file.write_text("Cet exo est un peu relou!")
    print(file.text())

    return None




if __name__ == '__main__':
    test()
