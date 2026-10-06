

class MyService:
    def __init__(self, repo):
        self._repo = repo

    def get_board1(self):
        return self._repo.get_myboard().board1



class ComputerService:
    def __init__(self, repo):
        self._repo = repo

    def get_board2(self):
        return self._repo.get_computerboard().board2