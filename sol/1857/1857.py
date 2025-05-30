from collections import defaultdict, deque

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        indeg = [0] * n
        adjList = defaultdict(list)
        for a, b in edges:
            indeg[b] += 1
            adjList[a].append(b)
        buff = deque([i for i in range(n) if indeg[i] == 0])
        topoOrd = []
        while (s := len(buff)) != 0:
            for _ in range(s):
                node = buff.popleft()
                topoOrd.append(node)
                for nb in adjList[node]:
                    indeg[nb] -= 1
                    if indeg[nb] == 0:
                        buff.append(nb)
        if len(topoOrd) != n:
            return -1
        memo = [[0] * 26 for _ in range(n)]
        res = 1
        for i in topoOrd[::-1]:
            ic = ord(colors[i]) - ord('a')
            if len(adjList[i]) == 0:
                memo[i][ic] = 1
            for nb in adjList[i]:
                for c in range(26):
                    memo[i][c] = max(memo[i][c], memo[nb][c] + (1 if c == ic else 0))
                    res = max(res, memo[i][c])
        return res
