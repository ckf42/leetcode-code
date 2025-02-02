from collections import defaultdict, deque

class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        adjMap = defaultdict(list)
        for a, b in edges:
            adjMap[a].append(b)
            adjMap[b].append(a)
        color = [0] * (n + 1)
        indices = [-1] * (n + 1)
        gpCount = 0
        for i in range(1, n + 1):
            if color[i] != 0:
                continue
            buff = deque([i])
            c = 1
            nodeList = []
            while (s := len(buff)) != 0:
                for _ in range(s):
                    x = buff.popleft()
                    if color[x] == 3 - c:
                        return -1
                    if color[x] != 0:
                        continue
                    color[x] = c
                    nodeList.append(x)
                    buff.extend(adjMap[x])
                c = 3 - c
            maxD = 0
            for idx, x in enumerate(nodeList):
                indices[x] = idx
            for x in nodeList:
                visited = [False] * len(nodeList)
                buff = deque([x])
                d = 0
                while (s := len(buff)) != 0:
                    for _ in range(s):
                        y = buff.popleft()
                        idx = indices[y]
                        if visited[idx]:
                            continue
                        visited[idx] = True
                        buff.extend((nb for nb in adjMap[y] if not visited[indices[nb]]))
                    d += 1
                maxD = max(maxD, d)
            gpCount += maxD
        return gpCount
