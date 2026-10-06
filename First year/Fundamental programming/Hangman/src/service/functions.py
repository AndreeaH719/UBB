from src.domain.classes import Sentence
import random

class SentenceService:
    def __init__(self, repo):
        self._repo = repo

    def get_sentences(self):
        return self._repo.get_sentences()

    def add(self, s):
        '''
        :param s: the new sentence
        :return: the list with a new sentence added
        '''
        l = s.split()
        if len(l) < 2:
            raise ValueError('sentence must have at least one word')
        for i in range(len(l)):
            if len(l[i]) < 3:
                raise ValueError('a word must have at least 3 characters')
        sentence = Sentence(s)
        self._repo.add(sentence)


    def start(self, cont, l):
        c = 0
        for s in self.get_sentences():
            if c == cont:
                sentence = s
                break
            c += 1
        result = sentence.get_s
        ok = False
        for i in result:
            if not ok:
                first_letter = i
                ok = True
            last_letter = i

        mask = []
        ok = False
        for j in range(len(result)):
            i = result[j]
            if i == first_letter:
                mask.append(first_letter)
            elif i == last_letter:
                mask.append(last_letter)
            elif i == " ":
                mask.append(" ")
                ok = True
            elif i != " " and ok == True:
                mask.append(i)
                ok = False
            elif result[j + 1] == " " and j + 1 < len(result):
                mask.append(i)
            else: mask.append("_")
        return mask

    def play(self, m, cont, l):
        c = 0
        for s in self.get_sentences():
            if c == cont:
                sentence = s
                break
            c += 1
        result = sentence.get_s
        found = False
        l = l.lower()
        '''''
        if l != "":
            for i, c in enumerate(result):
                if c.lower() == l:
                    m[i] = c
                    found = True
        '''''
        for i in range(len(result)):
            if result[i].lower() == l:
                m[i] = l
                found = True
        mask_str = "".join(m)
        return mask_str, found



