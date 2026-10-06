

class LabyrintRepo:
    def __init__(self, file_name):
        self.file_name = file_name
        self.matrix = []
        self.load_file()

    def load_file(self):
        self.matrix = []
        try:
            with open(self.file_name, "r") as file:
                for line in file:
                    line = line.strip()
                    if line == "":
                        continue
                    row = [int(x) for x in line.split()]
                    self.matrix.append(row)
        except FileNotFoundError:
            pass

    def save_file(self):
        with open(self.file_name, "w") as file:
            for line in self.matrix:
                file.write(" ".join(str(x) for x in line) + "\n")

    def get_matrix(self):
        return self.matrix.copy()