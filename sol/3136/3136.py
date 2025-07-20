class Solution:
    VOWEL = 'aeiouAEIOU'
    FORBID = '@#$'
    DIGITS = '0123456789'
    def isValid(self, word: str) -> bool:
        return len(word) >= 3 \
            and all(c not in self.FORBID for c in word) \
            and any(c in self.VOWEL for c in word) \
            and any(c not in self.VOWEL + self.DIGITS for c in word)
