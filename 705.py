class MyHashSet:
    capacity = 1 << 10
    mask = (1 << 10) - 1

    def __init__(self):
        self.table = tuple(list() for i in range(self.capacity))

    def __computeHash(self, key: int) -> int:
        return ((key & self.mask) + 142) & self.mask

    def add(self, key: int) -> None:
        k = self.__computeHash(key)
        if key not in self.table[k]:
            self.table[k].append(key)

    def remove(self, key: int) -> None:
        k = self.__computeHash(key)
        try:
            idx = self.table[k].index(key)
            del self.table[k][idx]
        except ValueError:
            pass

    def contains(self, key: int) -> bool:
        return key in self.table[self.__computeHash(key)]

