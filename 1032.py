class StreamChecker:
    def __init__(self, words: List[str]):
        self.root = dict()
        self.qptrs = []
        for w in words:
            ptr = self.root
            for c in w:
                if c not in ptr:
                    ptr[c] = dict()
                ptr = ptr[c]
            ptr['='] = True

    def query(self, letter: str) -> bool:
        self.qptrs.append(self.root)
        self.qptrs = [ptr[letter] for ptr in self.qptrs if letter in ptr]
        return any('=' in ptr for ptr in self.qptrs)

