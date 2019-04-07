import elem
import elements

class Page:

    def __init__(self, elem):
        self.elem = elem
        self.dic_valid = self.build_valid()

    
    def build_valid(self):

        list_valid = [a for a in dir(elements) if not a.startswith('__') and a != 'elem']
        dic_valid = {}
        for key in list_valid:
            dic_valid[key] = getattr(elements, key)
        dic_valid['Text'] = elem.Text

        return dic_valid


    def check_type(self):

        for e in self.elem.content:
            if not isinstance(e, tuple(self.dic_valid.values())):
                return False
        return True



    def check_content(self):

        if self.elem.tag == 'html':
            return all([len(self.elem.content) == 2\
                    and isinstance(e,t) for e,t in\
                    zip(self.elem.content, [self.dic_valid['Head'],\
                    self.dic_valid['Body']])])

        if self.elem.tag == 'head':
            return all([len(self.elem.content) == 1\
                    and isinstance(self.elem.content[0],self.dic_valid['Title'])])

        if self.elem.tag in ['body','div']:
            list_name = ["H1", "H2", "Div","Table", "Ul", "Ol", "Span", "Text"]
            list_class = [v for k,v in self.dic_valid.items() if k in list_name]
            return all([isinstance(e,tuple(list_class)) for e in self.elem.content])

        if self.elem.tag in ['title', 'h1', 'h2', 'li', 'th', 'td']:
            return all([len(self.elem.content) == 1\
                    and isinstance(self.elem.content[0], self.dic_valid["Text"])])

        if self.elem.tag == 'p':
            return all([not self.elem.content\
                    or isinstance(e,self.dic_valid['Text']) for e in self.elem.content])

        if self.elem.tag == 'span':
            list_class = [v for k,v in self.dic_valid.items() if k in ['Text','P']]
            return all([not self.elem.content\
                    or isinstance(e,tuple(list_class)) for e in self.elem.content])

        if self.elem.tag in ['ol','ul']:
            return all([len(self.elem.content) > 0\
                    and isinstance(e, self.dic_valid["Li"]) for e in self.elem.content])

        if self.elem.tag == 'tr':
            list_class = [v for k,v in self.dic_valid.items() if k in ['Th','Td']]
            return all([len(self.elem.content) > 0\
                    and isinstance(e, tuple(list_class)) for e in self.elem.content])

        if self.elem.tag == 'th':
            return all([not isinstance(e, self.dic_valid['Td']) for e in sel.elem.content])

        if self.elem.tag == 'td':
            return all([not isinstance(e, self.dic_valid['Th']) for e in sel.elem.content])

        if self.elem.tag == 'table':
            return all([isinstance(e, self.dic_valid["Tr"]) for e in self.elem.content])

        return True


    def is_valid(self):

        if not self.check_type() or not self.check_content():
            return False
        for e in self.elem.content:
            if not isinstance(e,elem.Text) and Page(e).is_valid() == False:
                return False

        return True

    
    def __str__(self):

        result = self.elem.__str__()

        if self.elem.tag == 'html':
            result = '<!DOCTYPE html>\n' + result

        return result

    
    def write_to_file(self, filename):

        with open(filename, 'w') as f:
            f.write(self.__str__())

        return None



def test():
    e = elements.Html([elements.Head(elements.Title(elem.Text('"Hello ground!"'))), \
            elements.Body([elements.H1(elem.Text('"Oh no, not again!"')), \
            elements.Ol(elements.Li(elem.Text("hello")))])])
    p = Page(e)
    print(p.is_valid())
    print(p)
    p.write_to_file("test.html")
    return None


if __name__ == "__main__":
    test()
            


