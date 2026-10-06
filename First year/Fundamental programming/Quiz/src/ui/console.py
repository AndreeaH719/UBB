from src.repository.repo import QuestionsRepo, QuizHard, QuizEasy, QuizMedium
from src.services.functions import QuestionService


class Console:
    def __init__(self, service):
        self._service = service

    def run(self):
        print("add <id> <text> <ca> <cb> <cc> <corect> <dif>")
        print("get questions")

        while True:
            try:
                command_line = input("enter your command: ").strip()
                parts = command_line.split(maxsplit=1)
                if not parts:
                    continue
                command = parts[0]
                if len(parts) > 1:
                    args = parts[1]
                else:
                    args = ""

                if command == "get":
                    for q in self._service.get_questions():
                        print(q)

                elif command == "add":
                    id = int(args.split(",")[0])
                    text = args.split(",")[1]
                    ca = args.split(",")[2]
                    cb = args.split(",")[3]
                    cc = args.split(",")[4]
                    corect = args.split(",")[5]
                    dif = args.split(",")[6]
                    self._service.add(id, text, ca, cb, cc, corect, dif)
                elif command == "create":
                    try:
                        dif = args.split(",")[0]
                        no = int(args.split(",")[1])
                        file = args.split(",")[2]
                        self._service.create(dif, no, file)
                        print()
                        print(file)
                        for q in self._service.get_hard_quiz():
                            print(q)
                    except ValueError as ve:
                        print(ve)
                elif command == "start":
                    file = args
                    score = 0
                    if file == "hardquiz.txt":
                        for q in self._service.get_hard_quiz():
                            print(q)
                            your_answer = input("enter your answer: ").strip()
                            corect_a = q.corect
                            if your_answer == corect_a and q.dif == "easy":
                                score += 1
                            elif your_answer == corect_a and q.dif == "hard":
                                score += 3
                            elif your_answer == corect_a and q.dif == "medium":
                                score += 2
                            print(f"the correct answer is {corect_a}")
                        print("end of the quiz")
                        print(f"your score is {score}")

                else:
                    print("invalid command")
            except ValueError as ve:
                print(ve)

if __name__ == "__main__":
    r = QuestionsRepo("q.txt")
    rh = QuizHard("hardquiz.txt")
    re = QuizEasy("easyquiz.txt")
    rm = QuizMedium("mediumquiz.txt")
    s = QuestionService(r, rh, re, rm)
    c = Console(s)
    c.run()