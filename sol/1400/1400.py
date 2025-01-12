from collections import Counter

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        counter = Counter(s)
        exceptCount = 0
        for c, freq in counter.items():
            if freq & 1:
                exceptCount += 1
        return exceptCount <= k
