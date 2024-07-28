class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        tag = [0] * n
        def dfs(x):
            if tag[x] == 1:
                return False
            if tag[x] == 2:
                return True
            tag[x] = 1
            for y in graph[x]:
                if not dfs(y):
                    return False
            tag[x] = 2
            return True
        return [i for i in range(n) if dfs(i)]
