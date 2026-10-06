from src.domain.classes import QuestionList


class QuestionService:
    def __init__(self, repo, repo2, repo3, repo4):
        self._repo = repo
        self._repo2 = repo2
        self._repo3 = repo3
        self._repo4 = repo4

    def get_questions(self):
        return self._repo.get_questions()

    def add(self, id, text, ca, bb, cc, corect, dif):
        """
        :param id:
        :param text:
        :param ca:
        :param bb:
        :param cc:
        :param corect:
        :param dif:
        :return:
        """
        q = QuestionList(id, text, ca, bb, cc, corect, dif)
        self._repo.add(q)

    def create(self, dif, no, file):
        self._repo2.clear()
        self._repo3.clear()
        self._repo4.clear()
        if file == "hardquiz.txt":
           if no > len(self._repo.get_questions()):
                raise ValueError("not enough questions")
           hard_question = [q for q in self._repo.get_questions() if q.dif == dif]
           others = [q for q in self._repo.get_questions() if q.dif != dif]
           quiz = hard_question[:no]
           if len(hard_question) < no:
               for o in others:
                   while len(quiz) < no:
                       quiz.append(o)
           for q in quiz:
                self._repo2.add(q)
        elif file == "easyquiz.txt":
            if no > len(self._repo.get_questions()):
                raise ValueError("not enough questions")
            easy_question = [q for q in self._repo.get_questions() if q.dif == dif]
            others = [q for q in self._repo.get_questions() if q.dif != dif]
            quiz = easy_question[:no]
            if len(easy_question) < no:
                for o in others:
                    while len(quiz) < no:
                        quiz.append(o)
            for q in quiz:
               self._repo3.add(q)
        elif file == "mediumquiz.txt":
            if no > len(self._repo.get_questions()):
                raise ValueError("not enough questions")
            medium_question = [q for q in self._repo.get_questions() if q.dif == dif]
            others = [q for q in self._repo.get_questions() if q.dif != dif]
            quiz = medium_question[:no]
            if len(medium_question) < no:
                for o in others:
                    while len(quiz) < no:
                        quiz.append(o)
            for q in quiz:
                self._repo4.add(q)


    def get_hard_quiz(self):
        return self._repo2.get_hard_quiz()

    def get_easy_quiz(self):
        return self._repo3.get_easy_quiz()

    def get_medium_quiz(self):
        return self._repo4.get_medium_quiz()
