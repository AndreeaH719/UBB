
class Sentence:
    def __init__(self, s):
        self._s = s

    @property
    def get_s(self):
        return self._s

    def __str__(self):
        return f"{self._s}"