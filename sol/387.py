class Solution:
    def firstUniqChar(self, s: str) -> int:
        indices = {}
        for i, c in enumerate(s):
            if c not in indices:
                indices[c] = [i]
            elif len(indices[c]) < 2:
                indices[c].append(i)
        return min((l[0] for l in indices.values() if len(l) == 1), default=-1)
