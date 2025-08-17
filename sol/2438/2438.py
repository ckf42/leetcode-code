class Solution:
    TABLE = []
    def __init__(self):
        if len(self.TABLE) == 0:
            m = 10 ** 9 + 7
            self.TABLE.append(1)
            for _ in range(1, sum(range(30))):
                self.TABLE.append((self.TABLE[-1] * 2) % m)
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        powers_idx = []
        mask = 1
        idx = 0
        while mask <= n:
            if mask & n:
                powers_idx.append(idx)
            mask <<= 1
            idx += 1
        prefix = [0]  # sum(powers_idx[:i])
        for idx in powers_idx:
            prefix.append(prefix[-1] + idx)
        return [
            self.TABLE[prefix[b + 1] - prefix[a]]
            for a, b in queries
        ]
