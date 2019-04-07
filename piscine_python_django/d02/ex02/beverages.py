
class HotBeverage:

    def __init__(self):
        self.price = 0.30
        self.name = "hot beverage"

    @staticmethod
    def description():
        return "Just some hot water in a cup."

    def __str__(self):
        return "name : {0}\nprice : {1: .2f}\ndescription : {2}"\
                .format(self.name, self.price, self.description())


class Coffee(HotBeverage):

    def __init__(self):
        super().__init__()
        self.price = 0.40
        self.name = "coffee"

    @staticmethod
    def description():
        return "A coffee, to stay awake."


class Tea(HotBeverage):
    
    def __init__(self):
        super().__init__()
        self.name = "tea"


class Chocolate(HotBeverage):
    def __init__(self):
        super().__init__()
        self.price = 0.50
        self.name = "chocolate"

    @staticmethod
    def description():
        return "Chocolate, sweet chocolate..."


class Capuccino(HotBeverage):
    def __init__(self):
        super().__init__()
        self.price = 0.45
        self.name = "capuccino"

    @staticmethod
    def description():
        return "Un po’ di Italia nella sua tazza!"


def hot_beverages():
    h = HotBeverage()
    c = Coffee()
    t = Tea()
    choc = Chocolate()
    capu = Capuccino()
    print(h)
    print(c)
    print(t)
    print(choc)
    print(capu)


if __name__ == "__main__":
    hot_beverages()
