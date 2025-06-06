class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        parent = list(range(26))
        def getPar(x):
            while parent[x] != x:
                x, parent[x] = parent[x], parent[parent[x]]
            return x
        def unionGp(x, y):
            x = getPar(x)
            y = getPar(y)
            if x == y:
                return
            if x > y:
                x, y = y, x
            parent[y] = x
        oa = ord('a')
        for a, b in zip(s1, s2):
            unionGp(ord(a) - oa, ord(b) - oa)
        return ''.join(
            chr(getPar(ord(c) - oa) + oa)
            for c in baseStr
        )
