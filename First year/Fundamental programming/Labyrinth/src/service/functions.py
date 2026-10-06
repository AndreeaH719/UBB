from texttable import Texttable

class LabyrinthService:
    def __init__(self, lab):
        self._lab = lab
        self._ariadna = self.find_a()
        self._minotaur = self.find_m()

    def find_a(self):
        for i in range(1, self._lab.rows):
            if self._lab.matrix[i][1] == 0:
                return (i, 1)
        return (0, 1)

    def find_m(self):
        for i in range(1, self._lab.rows):
            if self._lab.matrix[i][self._lab.cols - 2] == 0:
                return (i, self._lab.cols - 2)
        return (0, self._lab.cols - 2)

    def print_matrix(self, ariadna=None, minotaur=None):
        table = Texttable()
        table.set_cols_align(['c'] * self._lab.cols)
        for i in range(self._lab.rows):
            row = []
            for j in range(self._lab.cols):
                if ariadna == (i, j):
                    row.append("A")
                elif minotaur == (i, j):
                    row.append("M")
                elif self._lab.matrix[i][j] == 1:
                    row.append("X")
                elif self._lab.matrix[i][j] == 9:
                    row.append("-")
                else:
                    row.append(" ")
            table.add_row(row)
        return table.draw()

    def draw(self):
        return self.print_matrix(self._ariadna, self._minotaur)

    def move1(self, direction):
        x, y = self._ariadna
        dx, dy = 0, 0
        if direction == "up":
            dx = -1
        elif direction == "down":
            dx = 1
        elif direction == "left":
            dy = -1
        elif direction == "right":
               dy = 1

        nx, ny = x + dx, y + dy

        if 0 <= nx < self._lab.rows and 0 <= ny < self._lab.cols:
            if self._lab.matrix[nx][ny] == 0 or self._lab.matrix[nx][ny] == 9:
                self._ariadna = nx, ny
            else:
                raise ValueError("invalid direction")
        else:
            raise ValueError("Invalid direction")

    def move2(self):
        x, y = self._ariadna
        dx, dy = 0, 0
        if self._lab.matrix[x+1][y] in [0,9]:
                    dx, dy = dx + 1, dy
        elif self._lab.matrix[x][y+1] in [0,9]:
                    dx, dy = dx, dy + 1
        elif self._lab.matrix[x-1][y] in [0,9]:
                    dx, dy = dx -1, dy
        elif self._lab.matrix[x][y-1] in [0,9]:
                    dx, dy = dx, dy - 1
        nx, ny = x + dx, y + dy

        if 0 <= nx < self._lab.rows and 0 <= ny < self._lab.cols:
            if self._lab.matrix[nx][ny] == 0 or self._lab.matrix[nx][ny] == 9:
                self._ariadna = nx, ny
            else:
                raise ValueError("invalid direction")
        else:
            raise ValueError("Invalid direction")

    def win(self):
        x, y = self._ariadna
        if self._lab.matrix[x][y] == 9:
            return True


    def move3(self, n):
        x, y = self._ariadna
        dx, dy = 0, 0
        if self._lab.matrix[x + 1][y] in [0, 9]:
            dx, dy = dx + 1, dy
        elif self._lab.matrix[x][y + 1] in [0, 9]:
            dx, dy = dx, dy + 1
        elif self._lab.matrix[x - 1][y] in [0, 9]:
            dx, dy = dx - 1, dy
        elif self._lab.matrix[x][y - 1] in [0, 9]:
            dx, dy = dx, dy - 1

        while n > 0:
            nx, ny = x + dx, y + dy
            if 0 <= nx < self._lab.rows and 0 <= ny < self._lab.cols:
                if self._lab.matrix[nx][ny] == 0 or self._lab.matrix[nx][ny] == 9:
                    self._ariadna = nx, ny
                    x,y = nx, ny
                else:
                    raise ValueError("invalid direction")
            else:
                raise ValueError("Invalid direction")
            n = n - 1

    def move_min(self, n):
        x, y = self._minotaur
        dx, dy = 0, 0
        if self._lab.matrix[x + 1][y] in [0, 9]:
            dx, dy = dx + 1, dy
        elif self._lab.matrix[x][y + 1] in [0, 9]:
            dx, dy = dx, dy + 1
        elif self._lab.matrix[x - 1][y] in [0, 9]:
            dx, dy = dx - 1, dy
        elif self._lab.matrix[x][y - 1] in [0, 9]:
            dx, dy = dx, dy - 1

        while n > 0:
            nx, ny = x + dx, y + dy
            if 0 <= nx < self._lab.rows and 0 <= ny < self._lab.cols:
                if self._lab.matrix[nx][ny] == 0 or self._lab.matrix[nx][ny] == 9:
                    self._minotaur = nx, ny
                    x, y = nx, ny
                else:
                    raise ValueError("invalid direction")
            else:
                raise ValueError("Invalid direction")
            n = n - 1






