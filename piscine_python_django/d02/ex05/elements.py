import elem

class Html(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='html', attr=attributes, content=elem)

class Head(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='head', attr=attributes, content=elem)

class Body(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='body', attr=attributes, content=elem)

class Title(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='title', attr=attributes, content=elem)

class Meta(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='meta', attr=attributes, content=elem, tag_type='simple')

class Img(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='img', attr=attributes, content=elem, tag_type='simple')

class Table(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='table', attr=attributes, content=elem)

class Th(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='th', attr=attributes, content=elem)

class Tr(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='tr', attr=attributes, content=elem)

class Td(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='td', attr=attributes, content=elem)

class Ul(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='ul', attr=attributes, content=elem)

class Ol(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='ol', attr=attributes, content=elem)

class Li(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='li', attr=attributes, content=elem)

class H1(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='h1', attr=attributes, content=elem)

class H2(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='h2', attr=attributes, content=elem)

class P(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='p', attr=attributes, content=elem)

class Div(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='div', attr=attributes, content=elem)

class Span(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='span', attr=attributes, content=elem)

class Hr(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='hr', attr=attributes, content=elem, tag_type='simple')

class Br(elem.Elem):

    def __init__(self, elem=None, attributes={}):
        super().__init__(tag='br', attr=attributes, content=elem, tag_type='simple')


if __name__ == "__main__":
    print(Html([Head(Title(elem.Text('"Hello ground!"'))),
            Body([H1(elem.Text('"Oh no, not again!"')),
            Img(attributes={"src":"http://i.imgur.com/pfp3T.jpg"})])]))
