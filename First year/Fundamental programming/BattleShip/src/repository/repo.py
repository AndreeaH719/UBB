from src.domain.board_class import MyBoard, ComputerBoard


class GameRepo:
    def __init__(self):
        self._myboard = MyBoard(6, 6)
        self._computerboard = ComputerBoard(6, 6)

    def get_myboard(self):
        return self._myboard
    def get_computerboard(self):
        return self._computerboard