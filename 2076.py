class Solution:
    def friendRequests(self, n: int, restrictions: List[List[int]], requests: List[List[int]]) -> List[bool]:
        parent = list(range(n))
        size = [1] * n
        def getPar(x):
            while parent[x] != x:
                x, parent[x] = parent[x], parent[parent[x]]
            return x
        def unionGp(x, y):
            x = getPar(x)
            y = getPar(y)
            if x == y:
                return
            if size[x] < size[y]:
                x, y = y, x
            parent[y] = x
            size[x] += size[y]
        res = []
        for u, v in requests:
            u, v = getPar(u), getPar(v)
            if u > v:
                u, v = v, u
            valid = True
            for a, b in restrictions:
                a, b = getPar(a), getPar(b)
                if a > b:
                    a, b = b, a
                if u == a and v == b:
                    valid = False
                    break
            res.append(valid)
            if valid:
                unionGp(u, v)
        return res
