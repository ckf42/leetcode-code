from bisect import bisect

class Solution:
    @staticmethod
    def f(s: str) -> int:
        c = '~'
        f = 0
        for x in s:
            if x < c:
                c = x
                f = 1
            elif x == c:
                f += 1
        return f
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        n = len(words)
        refFreq = sorted(self.f(w) for w in words)
        return [
            n - bisect(refFreq, self.f(q))
            for q in queries
        ]
