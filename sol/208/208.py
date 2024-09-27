class Trie:
    def __init__(self):
        self.root = dict()

    def insert(self, word: str) -> None:
        ptr = self.root
        for c in word:
            if c not in ptr:
                ptr[c] = dict()
            ptr = ptr[c]
        ptr['$'] = True

    def search(self, word: str) -> bool:
        ptr = self.root
        for c in word:
            if c not in ptr:
                return False
            ptr = ptr[c]
        return '$' in ptr

    def startsWith(self, prefix: str) -> bool:
        ptr = self.root
        for c in prefix:
            if c not in ptr:
                return False
            ptr = ptr[c]
        return True


