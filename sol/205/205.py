class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        return len(frozenset(zip(s, t))) == len(frozenset(s)) == len(frozenset(t))
