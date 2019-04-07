#!/usr/bin/python3


class Text(str):
    """
    A Text class to represent a text you could use with your HTML elements.

    Because directly using str class was too mainstream.
    """

    def __str__(self):
        """
        Do you really need a comment to understand this method?..
        """

        check_text = super().__str__()
        check_text = check_text.replace('<', '&lt;')
        check_text = check_text.replace('>', '&gt;')
        check_text = check_text.replace('"', '&quot;')
        check_text = check_text.replace('\n', '\n<br />\n')

        return check_text

class Elem:
    """
    Elem will permit us to represent our HTML elements.
    """
    class ValidationError(Exception):
        def __init__(self):
            super().__init__()

    def __init__(self, tag='div', attr={}, content=None, tag_type='double'):
        """
        __init__() method.

        Obviously.
        """
        self.tag = tag
        self.attr = attr
        self.content = []
        if content != None:
            self.add_content(content)
        self.tag_type = tag_type


    def __str__(self):
        """
        The __str__() method will permit us to make a plain HTML representation
        of our elements.
        Make sure it renders everything (tag, attributes, embedded
        elements...).
        """


        if self.tag_type == 'double':
            content_str = self.__make_content()
            if content_str != '':
                content_str += '\n'
            result = "<{0}{1}>{2}".format(self.tag, self.__make_attr(), content_str)
            result += "</{}>".format(self.tag)
        elif self.tag_type == 'simple':
            result = "<{0}{1} />".format(self.tag, self.__make_attr())
        else:
            raise AttributeError("Wrong tag type")
        return result

    def __make_attr(self):
        """
        Here is a function to render our elements attributes.
        """
        result = ''
        for pair in sorted(self.attr.items()):
            result += ' ' + str(pair[0]) + '="' + str(pair[1]) + '"'
        return result

    def __make_content(self):
        """
        Here is a method to render the content, including embedded elements.
        """

        if len(self.content) == 0:
            return ''
        result = ''
        for elem in self.content:
            result += "\n{}".format(elem).replace('\n','\n  ')
        return result

    def add_content(self, content):
        if not Elem.check_type(content):
            raise Elem.ValidationError
        if type(content) == list:
            self.content += [elem for elem in content if elem != Text('')]
        elif content != Text(''):
            self.content.append(content)

    @staticmethod
    def check_type(content):
        """
        Is this object a HTML-compatible Text instance or a Elem, or even a
        list of both?
        """
        return (isinstance(content, Elem) or type(content) == Text or
                (type(content) == list and all([type(elem) == Text or
                                                isinstance(elem, Elem)
                                                for elem in content])))


if __name__ == '__main__':
   elem_title = Elem(tag="title", content=Text('"Hello ground!"'))
   elem_head = Elem(tag="head", content=elem_title)
   elem_h1 = Elem(tag="h1", content=Text('"Oh no, not again!"'))
   elem_img = Elem(tag="img", attr={"src":"http://i.imgur.com/pfp3T.jpg"}, tag_type="simple")
   elem_body = Elem(tag='body', content=[elem_h1, elem_img])
   elem_html = Elem(tag='html', content=[elem_head, elem_body])
   print(elem_html)
