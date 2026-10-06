from src.domain.classes import Sentence


class SentenceRepo:
    def __init__(self, file_name):
        self._file_name = file_name
        self._sentence = [Sentence("anna has apples"),
                          Sentence("i want to sleep"),
                          Sentence("i hate uni"),
                          Sentence("what are you doing"),
                          Sentence("she wants home"),
                          ]
        self._load_file()

    def _load_file(self):
        try:
            with open(self._file_name, "r") as file:
                for line in file:
                    s = line.strip()
                    self._sentence.append(Sentence(s))
        except FileNotFoundError:
            pass

    def _save_file(self):
        with open(self._file_name, 'w') as file:
            for sen in self._sentence:
                file.write(f"{sen.get_s}\n")

    def get_sentences(self):
        return self._sentence.copy()

    def add(self, entity:Sentence):
        self._sentence.append(entity)
        self._save_file()