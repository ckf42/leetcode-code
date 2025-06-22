from collections import Counter

class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        freq = sorted(Counter(word).values())
        res = len(word)
        n = len(freq)
        prefix = 0
        suffix = res
        e = 0
        for s in range(n):
            while e < n and freq[e] - freq[s] <= k:
                suffix -= freq[e]
                e += 1
            res = min(res, prefix + suffix - (n - e) * (freq[s] + k))
            prefix += freq[s]
        return res
