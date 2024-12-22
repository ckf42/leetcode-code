from collections import defaultdict

class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adjList = defaultdict(list)
        for a, b in edges:
            adjList[a].append(b)
            adjList[b].append(a)
        parent = [-1] * n
        childList = defaultdict(set)
        st = [(0, 0)]
        while len(st) != 0:
            x, prev = st.pop()
            if parent[x] == -1:
                parent[x] = prev
                childList[prev].add(x)
                for y in adjList[x]:
                    st.append((y, x))
        childList[0].remove(0)
        leafs = list(x for x in range(n) if len(childList[x]) == 0)
        counter = 0
        def dfs(node):
            nonlocal counter
            for child in childList[node]:
                dfs(child)
            if values[node] % k == 0:
                counter += 1
            elif node != 0:
                values[parent[node]] += values[node]
        dfs(0)
        return counter
        
