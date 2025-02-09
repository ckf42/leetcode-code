class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        n = len(s1)
        indices = tuple(i for i in range(n) if s1[i] != s2[i])
        if len(indices) >= 3:
            return False
        if len(indices) < 2:
            return len(indices) == 0
        return s1[indices[0]] == s2[indices[1]] and s1[indices[1]] == s2[indices[0]]
