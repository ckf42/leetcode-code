class Solution:
    vowel = frozenset('aeiou')
    def doesAliceWin(self, s: str) -> bool:
        return any(c in self.vowel for c in s)
