from src.repository.repo import GameRepo
from src.service.functions import MyService, ComputerService
import random

class Console:
    def __init__(self, service1, service2):
        self._service1 = service1
        self._service2 = service2

    def print_b(self):
       print("player s board        computer board")
       print(" A B C D E F          A B C D E F")
       r1 = self._service1._repo.get_myboard().print_board1()
       r2 = self._service2._repo.get_computerboard().print_board2()
       for i, j in zip(r1, r2):
           print(f"{i}         {j}")


    def run(self):
        print("1.player s move")
        print("2.computer s move")
        print("exit")
        player_board = self._service1._repo.get_myboard()
        computer_board = self._service2._repo.get_computerboard()

        self.print_b()
        while True:
            try:
                    command_line = input().strip()
                    parts = command_line.split(maxsplit=1)
                    if not parts:
                        continue
                    command = parts[0]
                    if len(parts)  > 1:
                        args = parts[1]
                    else:
                        args = ""
                    if command == "ship":
                        coord = args
                        r1 = coord[0]
                        c1 = coord[1]
                        r2 = coord[2]
                        c2 = coord[3]
                        r3 = coord[4]
                        c3 = coord[5]

                        c1 = int(c1)
                        c2 = int(c2)
                        c3 = int(c3)
                        r1 = ord(r1) - ord('A')
                        r2 = ord(r2) - ord('A')
                        r3 = ord(r3) - ord('A')
                        self._service1._repo.get_myboard().place_ship1(r1, c1, r2, c2, r3, c3)
                        self.print_b()
                    elif command == "start":
                        self._service2._repo.get_computerboard().place_ship2()
                        self._service2._repo.get_computerboard().place_ship2()
                        self.print_b()
                    elif command == "attack":
                        ok = True
                        coord = args
                        r1 = coord[0]
                        c1 = coord[1]
                        r1 = ord(r1) - ord('A')
                        c1 = int(c1)
                        if self._service2._repo.get_computerboard().attack_computer(r1, c1) == "missed":
                            print("Player misses!")
                        else:
                            print("Player hits!")
                        if self._service2._repo.get_computerboard().ships_left2() == True:
                            print("YOU WON")
                            break
                        self.print_b()
                    elif command == "computer":
                        r1 = random.choice(["A", "B", "C", "D", "E", "F"])
                        c1 = random.randint(0, 5)
                        print(f"computer attack {r1}{c1}")
                        r1 = ord(r1) - ord('A')
                        c1 = int(c1)
                        if self._service1._repo.get_myboard().attack_me(r1, c1) == "missed":
                            print("Computer misses!")
                        else:
                            print("Computer hits!")
                        if self._service1._repo.get_myboard().ships_left1() == True:
                            print("COMPUTER WON")
                            break
                        self.print_b()
                    elif command == "cheat":
                        self._service2._repo.get_computerboard().print_board_cheat()








            except ValueError as ve:
                print(ve)

if __name__ == "__main__":
    r = GameRepo()
    s1 = MyService(r)
    s2 = ComputerService(r)
    m = Console(s1, s2)
    m.run()