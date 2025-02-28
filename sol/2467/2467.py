from collections import defaultdict, deque

class Solution:
    NOTVISITED = -2 * 10 ** 9
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        n = len(amount)
        bobed = [False] * n
        bobed[bob] = True
        treeEdges = defaultdict(list)
        for a, b in edges:
            treeEdges[a].append(b)
            treeEdges[b].append(a)
        parent = [-1] * n
        parent[0] = 0
        buff = deque([0])
        while (s := len(buff)) != 0:
            for _ in range(s):
                node = buff.popleft()
                for nb in treeEdges[node]:
                    if parent[nb] != -1:
                        continue
                    parent[nb] = node
                    buff.append(nb)
        aTotal = [self.NOTVISITED] * n
        aTotal[0] = amount[0]
        buff = deque([0])
        res = self.NOTVISITED
        while (s := len(buff)) != 0:
            bob = parent[bob]
            bobed[bob] = True
            for _ in range(s):
                node = buff.popleft()
                for nb in treeEdges[node]:
                    if nb == parent[node]:
                        continue
                    aTotal[nb] = aTotal[node]
                    if nb == bob:
                        aTotal[nb] += amount[nb] // 2
                    elif not bobed[nb]:
                        aTotal[nb] += amount[nb]
                    if len(treeEdges[nb]) == 1:
                        res = max(res, aTotal[nb])
                    else:
                        buff.append(nb)
        return res
