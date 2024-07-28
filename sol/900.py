class RLEIterator:
    def __init__(self, encoding: List[int]):
        self.data = encoding
        self.ptr = 0

    def next(self, n: int) -> int:
        lastOut = -1
        while self.ptr < len(self.data):
            if n <= self.data[self.ptr]:
                self.data[self.ptr] -= n
                return self.data[self.ptr + 1]
            else:
                n -= self.data[self.ptr]
                lastOut = self.data[self.ptr + 1]
                self.ptr += 2
        return lastOut if n == 0 else -1

