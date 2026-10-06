


class Labyrinth:
    def __init__(self, matrix):
        self._matrix = matrix
        self._rows = len(matrix)
        self._cols = len(matrix[0])

    @property
    def matrix(self):
        return self._matrix
    @property
    def rows(self):
        return self._rows
    @property
    def cols(self):
        return self._cols

    def is_wall(self, i, j):
        return self._matrix[i][j] == 1

    def is_exit(self, i, j):
        return self._matrix[i][j] == 9

    def is_empty(self, i, j):
        return self._matrix[i][j] == 0







