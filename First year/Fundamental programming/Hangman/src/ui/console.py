from src.repository.repo import SentenceRepo
from src.service.functions import SentenceService
import random

class Console:
    def __init__(self, service):
        self._service = service

    def run(self):
        print("read")
        print("add <s>")
        print("start")
        print("play")
        print("quit")
        history = []
        h = []
        while True:
            try:
                command_line= input("enter command: ").strip()
                parts = command_line.split(maxsplit=1)
                if not parts:
                    continue
                command = parts[0]
                if len(parts) > 1:
                    args = parts[1]
                else:
                    args = ""

                if command == "read":
                    for s in self._service.get_sentences():
                        history.append(s)
                        print(s)
                elif command == "add":
                    while True:
                        try:
                            s = args.strip()
                            if s in history:
                                raise ValueError("the sentence already exists")
                            break
                        except ValueError as ve:
                            print(ve)
                    try:
                        s = args.strip()
                        self._service.add(s)
                        history.append(s)
                    except ValueError as ve:
                        print(ve)
                elif command == "start":
                            cont = random.randint(0, len(self._service.get_sentences()) - 1)
                            ok = 1
                            hm = "hangman"
                            i_won = True
                            j = 0
                            l1 = self._service.start(cont, 0)
                            l_s =  "".join(l1)
                            if ok == 1:
                                print(f"{l_s} - {h}")
                                ok = 0
                            '''
                            command_line1 = input("").strip()
                            parts1 = command_line1.split(maxsplit=1)
                            command1 = parts1[0]
                            args1 = parts1[1]
                            '''

                elif command == "guess":
                                l = args.strip()
                                L, found = self._service.play(l1, cont, l)
                                if found == True:
                                    h1 = "".join(h)
                                    L = "".join(L)
                                    print(f"{L} - {h1}")
                                else:
                                    h.append(hm[0])
                                    hm = hm[1:]
                                    h1 = "".join(h)
                                    L = "".join(L)
                                    print(f"{L} - {h1}")

                                if len(h1) == len("hangman"):
                                     print("COMPUTER WON")
                                     return
                                else:
                                    for i in l1:
                                        if i == "_":
                                            i_won = False
                                    if i_won:
                                        print("YOU WON")
                                        return
                elif command == "exit":
                                break
            except ValueError as ve:
                print(ve)

if __name__ == "__main__":
    r = SentenceRepo("sentences.txt")
    s = SentenceService(r)
    c = Console(s)
    c.run()