from collections import defaultdict

class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        edgeList = defaultdict(set)
        m = len(grid)
        n = len(grid[0])
        visited = [[False] * n for _ in range(m)]
        nodeSet = set()
        comp = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and not visited[i][j]:
                    comp += 1
                    if comp > 1:
                        return 0
                    st = [(i, j)]
                    while len(st) != 0:
                        a, b = st.pop()
                        if visited[a][b]:
                            continue
                        visited[a][b] = True
                        nodeSet.add((a, b))
                        if a != 0 and grid[a - 1][b] == 1:
                            edgeList[(a, b)].add((a - 1, b))
                            edgeList[(a - 1, b)].add((a, b))
                            nodeSet.add((a - 1, b))
                            st.append((a - 1, b))
                        if a != m - 1 and grid[a + 1][b] == 1:
                            edgeList[(a, b)].add((a + 1, b))
                            edgeList[(a + 1, b)].add((a, b))
                            nodeSet.add((a + 1, b))
                            st.append((a + 1, b))
                        if b != 0 and grid[a][b - 1] == 1:
                            edgeList[(a, b)].add((a, b - 1))
                            edgeList[(a, b - 1)].add((a, b))
                            nodeSet.add((a, b - 1))
                            st.append((a, b - 1))
                        if b != n - 1 and grid[a][b + 1] == 1:
                            edgeList[(a, b)].add((a, b + 1))
                            edgeList[(a, b + 1)].add((a, b))
                            nodeSet.add((a, b + 1))
                            st.append((a, b + 1))
        if comp == 0:
            return 0
        nodes = tuple(nodeSet)
        idxDict = {v: i for i, v in enumerate(nodes)}
        l = len(nodes)
        if l == 1:
            return 1
        for idx in range(l):
            if len(edgeList[nodes[idx]]) == 1:
                continue
            visited = [False] * l
            visited[idx] = True
            for nbCount, (a, b) in enumerate(edgeList[nodes[idx]]):
                if nbCount != 0 and not visited[idxDict[(a, b)]]:
                    return 1
                st = [(a, b)]
                while len(st) != 0:
                    x, y = st.pop()
                    p = idxDict[(x, y)]
                    if visited[p]:
                        continue
                    visited[p] = True
                    for nb in edgeList[(x, y)]:
                        if not visited[idxDict[nb]]:
                            st.append(nb)
        return 2
