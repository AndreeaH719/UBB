import unittest

from src.domain.classes import QuestionList
from src.repository.repo import QuestionsRepo, QuizHard, QuizEasy, QuizMedium
from src.services.functions import QuestionService


class Test(unittest.TestCase):
    def test_add(self):
        self._r = QuestionsRepo("q.txt")
        q = QuestionList(4, "What number is odd", "3", "6", "12", "3", "easy")
        self._r.add(q)
        found = False
        for i in self._r.get_questions():
            if i.id == 4:
                found = True
                break
        self.assertTrue(found)

    def test_create(self):
        self.repo1 = QuestionsRepo("q.txt")
        self.repo2 = QuizHard("hardquiz.txt")
        self.repo3 = QuizEasy("easyquiz.txt")
        self.repo4 = QuizMedium("mediumquiz.txt")
        s = QuestionService(self.repo1, self.repo2, self.repo3, self.repo4)
        l = []
        ok = False
        l =  s.create("hard", 2, "hardquiz.txt")
        if l != None:
            ok = True
        self.assertTrue(ok)


if __name__ == '__main__':
    unittest.main()
