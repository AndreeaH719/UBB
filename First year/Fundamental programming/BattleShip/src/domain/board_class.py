import random


class MyBoard:
    def __init__(self, row1, col1):
        self._row1 = row1
        self._col1 = col1
        self._board1 = [["." for x in range(col1)] for y in range(row1)]

    @property
    def row1(self):
        return self._row1
    @property
    def col1(self):
        return self._col1
    @property
    def board1(self):
        return self._board1
    @row1.setter
    def row1(self, row1):
        self._row1 = row1
    @col1.setter
    def col1(self, col1):
        self._col1 = col1

    def print_board1(self):
        lines = []
        for i in range(self._row1):
            r = f"{i}" + " ".join(self.board1[i])
            lines.append(r)
        return lines

    def place_ship1(self, r1, c1, r2, c2, r3, c3):
        if r1 > self._row1 or r2 > self._row1 or r3 > self._row1 or r1 < 0 or r2 < 0 or r3 < 0:
            raise ValueError("invalid coordinates")
        if c1 > self._col1 or c3 > self._col1 or c2 > self._col1 or c1 < 0 or c2 < 0 or c3 < 0:
            raise ValueError("invalid coordinates")
        for i in range(self._row1):
            for j in range(self._col1):
                if self._board1[i][j] == "." and (j == r1  and i == c1):
                    self._board1[i][j] = "+"
                elif self._board1[i][j] == "." and (i == c2 and j == r2):
                    self._board1[i][j] = "+"
                elif self._board1[i][j] == "." and (i == c3 and j == r3):
                    self._board1[i][j] = "+"

    def attack_me(self, r1, c1):
        if self._board1[c1][r1] == ".":
            self._board1[c1][r1] = "O"
            return "missed"
        else:
            self._board1[c1][r1] = "X"
            return "attacked"

    def ships_left1(self):
        ships_left1 = 0
        for i in range(self._row1):
            for j in range(self._col1):
                if self._board1[i][j] == "+":
                    ships_left1 += 1
        if ships_left1 == 0:
            return True
        return False




class ComputerBoard:
    def __init__(self, row2, col2):
        self._row2 = row2
        self._col2 = col2
        self._board2 = [["." for x in range(col2)] for y in range(row2)]

    @property
    def row2(self):
        return self._row2
    @property
    def col2(self):
        return self._col2
    @property
    def board2(self):
        return self._board2
    @row2.setter
    def row2(self, row2):
        self._row2 = row2
    @col2.setter
    def col2(self, col2):
        self._col2 = col2

    def print_board2(self):
        lines = []
        for i in range(self._row2):
            b_print = []
            for j in range(self._col2):
                c = self.board2[i][j]
                if c == "+":
                    b_print.append(".")
                else: b_print.append(c)
            r = f"{i}" + " ".join(b_print)
            lines.append(r)
        return lines


    def print_board_cheat(self):
        print(" A B C D E F")
        for i in range(self._row2):
            b_print = []
            for j in range(self._col2):
                c = self.board2[i][j]
                b_print.append(c)
            print(f"{i}" + " ".join(b_print))


    def place_ship2(self):
        while True:
            r1 = random.randint(0, self._row2)
            c1 = random.randint(0, self._col2)
            r2 = random.randint(0, self._row2)
            c2 = random.randint(0, self._col2)
            r3 = random.randint(0, self._row2)
            c3 = random.randint(0, self._col2)

            if (r1 >= 0 and r1 < self._row2 and r2 >= 0 and r2 < self._row2 and r3 >= 0
                    and r3 < self._row2  and c1 >= 0 and c1 < self._col2 and c2 >= 0
                    and c2 < self._col2 and c3 >= 0 and c3
                    < self._col2 and ((r2 == r1 + 1 and r3 == r2 + 1 and c1 == c2 == c3)
                    or( c2 == c1 + 1 and c3 == c2 + 1 and r1 == r2 == r3) )):
                break

        for i in range(self._row2):
            for j in range(self._col2):
                if self._board2[i][j] == "." and (j == r1 and i == c1):
                    self._board2[i][j] = "+"
                elif self._board2[i][j] == "." and (i == c2 and j == r2):
                    self._board2[i][j] = "+"
                elif self._board2[i][j] == "." and (i == c3 and j == r3):
                    self._board2[i][j] = "+"

    def attack_computer(self, r1, c1):
        if self._board2[c1][r1] == ".":
                self._board2[c1][r1] = "O"
                return "missed"
        else:
             self._board2[c1][r1] = "X"
             return "attacked"

    def ships_left2(self):
        ships_left2 = 0
        for i in range(self._row2):
            for j in range(self._col2):
                if self._board2[i][j] == "+":
                    ships_left2 += 1
        if ships_left2 == 0:
            return True
        return False



