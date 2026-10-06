import unittest

from src.domain.classes import Sentence
from src.repository.repo import SentenceRepo


class Test(unittest.TestCase):
    def test_add(self):
        self.r = SentenceRepo("sentences.txt")
        S = Sentence("piastri wdc")
        self.r.add(S)
        found = False
        for s in self.r.get_sentences():
            if s == S:
                found = True
                break
        self.assertTrue(found)

if __name__ == '__main__':
    unittest.main()