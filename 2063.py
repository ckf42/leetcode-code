class Solution:
    def countVowels(self, word: str) -> int:
        res = 0
        n = len(word)
        for i, c in enumerate(word):
            if c in 'aeiou':
                res += (i + 1) * (n - i)
        return res
