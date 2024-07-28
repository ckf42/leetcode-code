from collections import defaultdict, deque

class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        edgeList = defaultdict(list)
        for u, v in edges:
            edgeList[u].append(v)
            edgeList[v].append(u)
        q = deque((1,))
        reachLvls = [list() for _ in range(n + 1)]
        lvl = 0
        while len(reachLvls[n]) < 2:
            s = len(q)
            for _ in range(s):
                u = q.popleft()
                if len(reachLvls[u]) != 0 and reachLvls[u][-1] >= lvl:
                    continue
                reachLvls[u].append(lvl)
                if len(reachLvls[n]) == 2:
                    break
                for v in edgeList[u]:
                    if len(reachLvls[v]) < 2:
                        q.append(v)
            lvl += 1
        res = 0
        for i in range(lvl - 1):
            if (q := res // change) & 1:
                res = (q + 1) * change
            res += time
        return res
