from collections import deque

class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        dist = [n - 1 - i for i in range(n)]
        edges = {
            i: [i - 1]
            for i in range(1, n)
        }
        edges[0] = []
        q = len(queries)
        res = [n] * q
        for i, e in enumerate(queries):
            edges[e[1]].append(e[0])
            buff = deque([e[1]])
            while len(buff) != 0:
                x = buff.popleft()
                for nb in edges[x]:
                    if dist[x] + 1 < dist[nb]:
                        dist[nb] = dist[x] + 1
                        buff.append(nb)
            res[i] = dist[0]
        return res
