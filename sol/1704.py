class Solution:
    vs = frozenset('aeiouAEIOU')

    def halvesAreAlike(self, s: str) -> bool:
        return sum(c in self.vs for c in s[:len(s) // 2]) == sum(c in self.vs for c in s[len(s) // 2:])
