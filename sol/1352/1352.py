class ProductOfNumbers:
    def __init__(self):
        self.seq: list[int] = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.seq = [1]
        else:
            self.seq.append(self.seq[-1] * num)

    def getProduct(self, k: int) -> int:
        n = len(self.seq)
        if k >= n:
            return 0
        return self.seq[-1] // self.seq[n - k - 1]

