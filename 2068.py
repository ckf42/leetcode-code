class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        f1 = [0] * 26
        f2 = [0] * 26
        for c in word1:
            f1[ord(c) - ord('a')] += 1
        for c in word2:
            f2[ord(c) - ord('a')] += 1
        for a, b in zip(f1, f2):
            if abs(a - b) > 3:
                return False
        return True
