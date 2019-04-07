import random
import beverages


class CoffeeMachine:

    def __init__(self):
        self.obsolescence = 10

    class EmptyCup(beverages.HotBeverage):
        
        def __init__(self):
            super().__init__()
            self.name = "empty cup"
            self.price = 0.90

        @staticmethod
        def description():
            return "An empty cup?! Gimme my money back!"


    class BrokenMachineException(Exception):

        def __init__(self):
            super().__init__()
            self.message = "This coffee machine has to be repaired."

    def repair(self):
        self.obsolescence = 10

    def serve(self, Beverage):

        if self.obsolescence == 0:
            raise self.BrokenMachineException

        liste_cup = ["full", "empty"]
        if random.choice(liste_cup) == "full":
            self.obsolescence -= 1
            return Beverage()
        else:
            return self.EmptyCup()


def test():
    cm = CoffeeMachine()
    for i in range(50):
        try:
            print(cm.serve(beverages.Tea).name)
        except CoffeeMachine.BrokenMachineException as e:
            print(e.message)
            cm.repair()


if __name__ == "__main__":
    test()
