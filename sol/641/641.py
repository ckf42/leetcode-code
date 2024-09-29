class MyCircularDeque:
    def __init__(self, k: int):
        self.k = k
        self.data = [-1] * (k + 1)
        self.begin = 0
        self.end = 0

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        self.begin = (self.begin + self.k) % (self.k + 1)
        self.data[self.begin] = value
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        self.data[self.end] = value
        self.end = (self.end + 1) % (self.k + 1)
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        self.begin = (self.begin + 1) % (self.k + 1)
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        self.end = (self.end + self.k) % (self.k + 1)
        return True

    def getFront(self) -> int:
        return -1 if self.isEmpty() else self.data[self.begin]

    def getRear(self) -> int:
        return -1 if self.isEmpty() else self.data[(self.end + self.k) % (self.k + 1)]

    def isEmpty(self) -> bool:
        return self.begin == self.end

    def isFull(self) -> bool:
        return (self.end - self.begin + self.k + 1) % (self.k + 1) == self.k

