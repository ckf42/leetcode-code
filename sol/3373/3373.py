from collections import defaultdict

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        n = len(edges1) + 1
        m = len(edges2) + 1
        adj1 = defaultdict(list)
        for a, b in edges1:
            adj1[a].append(b)
            adj1[b].append(a)
        adj2 = defaultdict(list)
        for a, b in edges2:
            adj2[a].append(b)
            adj2[b].append(a)
        def dfs(node, gp, adj, gpid):
            if gpid[node] != 0:
                return
            gpid[node] = gp
            for nb in adj[node]:
                dfs(nb, 3 - gp, adj, gpid)
        gp1 = [0] * n
        dfs(0, 1, adj1, gp1)
        count1 = sum(x == 1 for x in gp1)
        gp2 = [0] * m
        dfs(0, 1, adj2, gp2)
        count2 = sum(x == 1 for x in gp2)
        count2 = max(count2, m - count2)
        return [
            (count1 if gp1[i] == 1 else n - count1) + count2
            for i in range(n)
        ]
