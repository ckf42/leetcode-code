class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        h = frozenset(allowed)
        res = 0
        for w in words:
            for c in w:
                if c not in h:
                    break
            else:
                res += 1
        return res
