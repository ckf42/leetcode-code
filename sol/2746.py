from functools import cache

class Solution:
    def minimizeConcatenatedLength(self, words: List[str]) -> int:
        n = len(words)
        @cache
        def dp(i, h, t):
            if i == n:
                return 0
            return max(
                dp(i + 1, h, words[i][-1]) + (t == words[i][0]),
                dp(i + 1, words[i][0], t) + (h == words[i][-1])
            )
        return sum(len(w) for w in words) - dp(1, words[0][0], words[0][-1])
