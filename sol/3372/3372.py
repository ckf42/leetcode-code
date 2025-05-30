from collections import defaultdict, deque

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
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
        secondMost = 0
        for i in range(m):
            count = 0
            buff = set([i])
            visited = [False] * m
            for _ in range(k):
                if len(buff) == 0:
                    break
                count += len(buff)
                for x in buff:
                    visited[x] = True
                buff = set([nb for x in buff for nb in adj2[x] if not visited[nb]])
            secondMost = max(secondMost, count)
        res = [secondMost] * n
        for i in range(n):
            visited = [False] * n
            count = 0
            buff = set([i])
            for _ in range(k + 1):
                if len(buff) == 0:
                    break
                count += len(buff)
                for x in buff:
                    visited[x] = True
                buff = set([nb for x in buff for nb in adj1[x] if not visited[nb]])
            res[i] += count
        return res
