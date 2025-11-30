from collections import defaultdict

class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adjList = defaultdict(list)
        for a, b in edges:
            adjList[a].append(b)
            adjList[b].append(a)
        expanded = [False] * n
        res = 0
        buff = [(0, 0)]
        while len(buff) != 0:
            node, prev = buff[-1]
            if not expanded[node]:
                for nb in adjList[node]:
                    if not expanded[nb]:
                        buff.append((nb, node))
                expanded[node] = True
            else:
                if values[node] % k == 0:
                    res += 1
                elif node != 0:
                    values[prev] += values[node]
                buff.pop()
        return res
