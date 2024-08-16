class Fancy:
    modulus = 10 ** 9 + 7
    minv = tuple(
        pow(i, -1, 10 ** 9 + 7)
        for i in range(1, 101)
    )
    def __init__(self):
        self.data = []
        self.a = 1
        self.ainv = 1
        self.b = 0

    def append(self, val: int) -> None:
        self.data.append(((val - self.b) * self.ainv) % self.modulus)

    def addAll(self, inc: int) -> None:
        self.b = (self.b + inc) % self.modulus

    def multAll(self, m: int) -> None:
        self.a = (self.a * m) % self.modulus
        self.ainv = (self.ainv * self.minv[m - 1]) % self.modulus
        self.b = (self.b * m) % self.modulus

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.data):
            return -1
        return (self.data[idx] * self.a + self.b) % self.modulus

