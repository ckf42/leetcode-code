class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        n = len(words)
        if n == 1:
            return list(words[0])
        k = frozenset(words[0])
        res = []
        for c in k:
            res.extend([c] * min(w.count(c) for w in words))
        return res
