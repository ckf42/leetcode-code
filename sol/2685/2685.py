from collections import defaultdict, deque

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        adjList = defaultdict(list)
        for a, b in edges:
            adjList[a].append(b)
            adjList[b].append(a)
        visited = [False] * n
        res = 0
        for i in range(n):
            if visited[i]:
                continue
            buff = deque([i])
            nodeCount = 0
            commonCount = len(adjList[i])
            while (s := len(buff)) != 0:
                for _ in range(s):
                    x = buff.popleft()
                    if visited[x]:
                        continue
                    visited[x] = True
                    nodeCount += 1
                    if len(adjList[x]) != commonCount:
                        commonCount = -1
                    buff.extend(adjList[x])
            if commonCount == nodeCount - 1:
                res += 1
        return res
