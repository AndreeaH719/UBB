from src.domain.classes import Labyrinth
from src.repository.repo import LabyrintRepo
from src.service.functions import LabyrinthService


class Console:
    def __init__(self, service):
        self.service = service

    def run(self):
        print("show")
        print("go <up/down/left/right>")
        while True:
            try:
                command_line = input("enter your command: ").strip()
                parts = command_line.split(maxsplit=1)
                if not parts:
                    continue
                command = parts[0]
                if len(parts)  > 1:
                    args = parts[1]
                else:
                    args = ""
                if command == "show":
                    r1 = self.service.draw().split("\n")
                    r2 = self.service.draw().split("\n")
                    for i,j in zip(r1, r2):
                        print(f"{i}           {j}")
                elif command == "go":
                    try:
                        no = 0
                        direction = args.lower()
                        self.service.move1(direction)
                        no = 1
                        self.service.move_min(no)
                        i = 0
                        print("0 1 2 3 4 5 6 7 8")
                        for l in self.service.draw():
                            print(f"{chr(ord("A") + i)} {l}")
                            i+=1
                        if self.service.win():
                            print("win")
                            break
                    except ValueError as ve:
                        print(ve)
                elif command == "move":
                    if len(args) < 1:
                        try:
                            self.service.move2()
                            self.service.move_min(1)
                            self.service.draw()
                            if self.service.win():
                                print("win")
                                break
                        except ValueError as ve:
                            print(ve)
                    else:
                        n = int(args.strip())
                        try:
                            self.service.move3(n)
                            self.service.move_min(n)
                            self.service.draw()
                            if self.service.win():
                                print("win")
                                break
                        except ValueError as ve:
                            print(ve)



            except ValueError as ve:
                print(ve)

if __name__ == "__main__":
    repo = LabyrintRepo("labyrinth.txt")
    matrix = repo.get_matrix()
    l = Labyrinth(matrix)
    s = LabyrinthService(l)
    c = Console(s)
    c.run()
