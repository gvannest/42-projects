import os, sys, ipdb, pytest
from termcolor import cprint, colored
from parsing import process_file

def test_this_shit():
    path = 'tests_unitaire/parsing/'
    cprint("Unitesting parsing errors", 'green')
    for idx, filename in enumerate(os.listdir(path)):
        print(colored("\nTesting %s:" % filename, attrs=['underline']))
        with pytest.raises(SystemExit) as pytest_wrapped_e:
            process_file(path+filename)
        assert pytest_wrapped_e.type == SystemExit, "ASSERT ERROR -> %s   %s/%s" % (path+filename, idx, len(os.listdir(path)))
        assert pytest_wrapped_e.value.code == 0, print(colored("ASSERT ERROR -> %s   %s/%s" % (path+filename, idx, len(os.listdir(path))), 'red'))
    cprint("\nPARSING ERRORS OK %s/%s\n\n" % (idx, idx), 'green')

    path = 'tests_unitaire/unsolvable/'
    cprint("Unitesting solvability", 'green')
    for idx, filename in enumerate(os.listdir(path)):
        print(colored("\nTesting %s:" % filename, attrs=['underline']))
        with pytest.raises(SystemExit) as pytest_wrapped_e:
            process_file(path+filename)
        assert pytest_wrapped_e.type == SystemExit, "ASSERT ERROR -> %s   %s/%s" % (path+filename, idx, len(os.listdir(path)))
        assert pytest_wrapped_e.value.code == 0, print(colored("ASSERT ERROR -> %s   %s/%s" % (path+filename, idx, len(os.listdir(path))), 'red'))
    cprint("\nPARSING ERRORS OK %s/%s\n\n" % (idx, idx), 'green')
