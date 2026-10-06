from src.domain.classes import QuestionList


class QuestionsRepo:
    def __init__(self, filename):
        self._filename = filename
        self._questions = [QuestionList(1, "Which number is prime", "1", "2", "4", "2", "hard"),
                           QuestionList(2, "Which number is even", "1", "5", "4", "4", "easy"),
                           QuestionList(3, "What is a color", "pink", "apple", "5", "pink", "medium"),
                           QuestionList(3, "What is a color", "pink", "apple", "5", "pink", "hard"),
                           QuestionList(3, "What is a color", "pink", "apple", "5", "pink", "medium"),
                           QuestionList(3, "What is a color", "pink", "apple", "5", "pink", "medium"),
                           ]

        self._load_file()

    def _load_file(self):
        try:
            with open(self._filename, "r") as file:
                for line in file:
                    id, text, ca, cb, cc, corect, dif = line.strip().split(',')
                    self._questions.append(QuestionList(int(id), text, ca, cb, cc, corect, dif))
        except FileNotFoundError:
            pass

    def _save_file(self):
        with open(self._filename, "w") as file:
            for q in self._questions:
                file.write(f"{q.id}, {q.text}, {q.ca}, {q.cb}, {q.cc}, {q.corect}, {q.dif}\n")

    def get_questions(self):
        return self._questions.copy()

    def add(self, entity:QuestionList):
        self._questions.append(entity)
        self._save_file()

class QuizHard:
    def __init__(self, filename):
        self._filename = filename
        self._q = []
        self._load_file()

    def _load_file(self):
        try:
            with open(self._filename, "r") as file:
                for line in file:
                    id, text, ca, cb, cc, corect, dif = line.strip().split(",")
                    self._q.append(QuestionList(int(id), text, ca, cb, cc, corect, dif))
        except FileNotFoundError:
            pass

    def _save_file(self):
        with open(self._filename, "w") as file:
            for q in self._q:
                file.write(f"{q.id}, {q.text}, {q.ca}, {q.cb}, {q.cc}, {q.corect}, {q.dif}\n")

    def add(self, entity: QuestionList):
        self._q.append(entity)
        self._save_file()

    def get_hard_quiz(self):
        return self._q.copy()

    def clear(self):
        self._q = []


class QuizEasy:
    def __init__(self, filename):
        self._filename = filename
        self._q = []
        self._load_file()

    def _load_file(self):
        try:
            with open(self._filename, "r") as file:
                for line in file:
                    id, text, ca, bb, cc, corect, dif = line.strip().split(",")
                    self._q.append(QuestionList(int(id), text, ca, bb, cc, corect, dif))
        except FileNotFoundError:
            pass

    def _save_file(self):
        with open(self._filename, "w") as file:
            for q in self._q:
                file.write(f"{q.id}, {q.text}, {q.ca}, {q.cb}, {q.cc}, {q.corect}, {q.dif}\n")

    def add(self, entity: QuestionList):
        self._q.append(entity)
        self._save_file()

    def get_easy_quiz(self):
        return self._q.copy()

    def clear(self):
        self._q = []

class QuizMedium:
    def __init__(self, filename):
        self._filename = filename
        self._q = []
        self._load_file()

    def _load_file(self):
        try:
            with open(self._filename, "r") as file:
                for line in file:
                    id, text, ca, bb, cc, corect, dif = line.strip().split(",")
                    self._q.append(QuestionList(int(id), text, ca, bb, cc, corect, dif))
        except FileNotFoundError:
            pass

    def _save_file(self):
        with open(self._filename, "w") as file:
            for q in self._q:
                file.write(f"{q.id}, {q.text}, {q.ca}, {q.cb}, {q.cc}, {q.corect}, {q.dif}\n")

    def add(self, entity: QuestionList):
        self._q.append(entity)
        self._save_file()


    def get_medium_quiz(self):
        return self._q.copy()

    def clear(self):
        self._q = []




