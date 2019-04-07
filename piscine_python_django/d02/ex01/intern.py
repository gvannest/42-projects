
class Intern:

    def __init__(self, name = "My name? I’m nobody, an intern, I have no name."):
        self.Name = name

    def __str__(self):
        return self.Name

    class Coffee:
        @staticmethod
        def __str__():
            return "This is the worst coffee you ever tasted."

    @staticmethod
    def work():
        raise Exception("I’m just an intern, I can’t do that...")

    def make_coffee(self):
        return self.Coffee()


if __name__ == "__main__":
    i1 = Intern()
    i2 = Intern("Mark")
    print(i1.Name)
    print(i2.Name)
    print(i2.make_coffee())
    try:
        i1.work()
    except Exception as e:
        print(type(e).__name__+' : '+ e.__str__())
