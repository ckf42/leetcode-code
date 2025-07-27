class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        n = len(nums)
        adj = [list() for _ in range(n)]
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)
        xorval = [-2] * n
        par = [-1] * n
        def comp_xor(node):
            nonlocal xorval
            nonlocal par
            if xorval[node] >= 0:
                return xorval[node]
            xorval[node] = -1
            res = nums[node]
            for child in adj[node]:
                if xorval[child] == -1:
                    continue
                par[child] = node
                res ^= comp_xor(child)
            xorval[node] = res
            return res
        comp_xor(0)
        for i, (a, b) in enumerate(edges):
            if par[a] != b:
                edges[i] = [b, a]
        res = -1
        for i in range(n - 1):
            a, b = edges[i]
            va = xorval[a]
            bb = b
            while bb != -1:
                xorval[bb] ^= va
                bb = par[bb]
            v0 = xorval[0]
            in_sub = [-1] * n
            in_sub[0] = 0
            in_sub[a] = 1
            def comp_sub(node):
                nonlocal in_sub
                if in_sub[node] == -1:
                    in_sub[node] = comp_sub(par[node])
                return in_sub[node]
            for x in range(n):
                comp_sub(x)
            for j in range(i + 1, n - 1):
                c, d = edges[j]
                if in_sub[d] == 0:
                    score = max(va, xorval[c], v0 ^ xorval[c]) \
                        - min(va, xorval[c], v0 ^ xorval[c])
                else:
                    score = max(va ^ xorval[c], xorval[c], v0) \
                        - min(va ^ xorval[c], xorval[c], v0)
                if res == -1 or score < res:
                    res = score
            bb = b
            while bb != -1:
                xorval[bb] ^= va
                bb = par[bb]
        return res
