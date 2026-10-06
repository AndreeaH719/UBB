
class QuestionList:
    def __init__(self, id, text, ca, cb, cc, corect, dif):
        self.__id = id
        self.__text = text
        self.__ca = ca
        self.__cb = cb
        self.__cc = cc
        self.__dif = dif
        self.__corect = corect

    @property
    def id(self):
        return self.__id
    @property
    def text(self):
        return self.__text

    @property
    def ca(self):
        return self.__ca
    @property
    def cb(self):
        return self.__cb
    @property
    def cc(self):
        return self.__cc
    @property
    def dif(self):
        return self.__dif
    @property
    def corect(self):
        return self.__corect
    @id.setter
    def id(self, value):
        self.__id = value
    @text.setter
    def text(self, value):
        self.__text = value
    @ca.setter
    def ca(self, value):
        self.__ca = value
    @cb.setter
    def cb(self, value):
        self.__cb = value
    @cc.setter
    def cc(self, value):
        self.__cc = value
    @dif.setter
    def dif(self, value):
        self.__dif = value
    @corect.setter
    def corect(self, value):
        self.__corect = value

    def __str__(self):
        return f"{self.id}, {self.text}, {self.ca}, {self.cb}, {self.cc}, {self.corect}, {self.dif}"