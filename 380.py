from random import choice

class RandomizedSet:

    def __init__(self):
        self.index: dict[int, int] = dict()
        self.items: list[int] = list()

    def insert(self, val: int) -> bool:
        if val in self.index:
            return False
        self.index[val] = len(self.items)
        self.items.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.index:
            return False
        last = self.items.pop()
        if last != val:
            self.index[last] = self.index[val]
            self.items[self.index[last]] = last
        del self.index[val]
        return True

    def getRandom(self) -> int:
        return choice(self.items)


