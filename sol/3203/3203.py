from collections import defaultdict, deque

class Solution:
    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        adjList1 = defaultdict(list)
        n = len(edges1) + 1
        for a, b in edges1:
            adjList1[a].append(b)
            adjList1[b].append(a)
        adjList2 = defaultdict(list)
        m = len(edges2) + 1
        for a, b in edges2:
            adjList2[a].append(b)
            adjList2[b].append(a)
        def getTreeLvlCount(adjList, vCount):
            visited = [False] * vCount
            q = deque((0,))
            lastNode = 0
            while len(q) != 0:
                x = q.popleft()
                if visited[x]:
                    continue
                lastNode = x
                visited[x] = True
                for nb in adjList[x]:
                    q.append(nb)
            q.append(lastNode)
            h = 0
            visited = [False] * vCount
            while (l := len(q)) != 0:
                for _ in range(l):
                    x = q.popleft()
                    visited[x] = True
                    for nb in adjList[x]:
                        if not visited[nb]:
                            q.append(nb)
                h += 1
            return h
        a = getTreeLvlCount(adjList1, n)
        b = getTreeLvlCount(adjList2, m)
        return max(a - 1, b - 1, a // 2 + b // 2 + 1)
