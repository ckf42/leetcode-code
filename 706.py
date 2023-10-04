class MyHashMap:
    CAPACITY = 1 << 10
    MASK = CAPACITY - 1

    def __init__(self):
        self.arr = tuple(deque() for _ in range(self.CAPACITY))

    def __computeHash(self, k: int) -> int:
        return ((k << 5) + k) & self.MASK

    def put(self, key: int, value: int) -> None:
        h = self.__computeHash(key)
        for i in range(len(self.arr[h])):
            if self.arr[h][i][0] == key:
                self.arr[h][i][1] = value
                return
        self.arr[h].append([key, value])

    def get(self, key: int) -> int:
        h = self.__computeHash(key)
        for i in range(len(self.arr[h])):
            if self.arr[h][i][0] == key:
                return self.arr[h][i][1]
        return -1

    def remove(self, key: int) -> None:
        h = self.__computeHash(key)
        for i in range(len(self.arr[h])):
            if self.arr[h][i][0] == key:
                self.arr[h][i][1] = -1
                return

