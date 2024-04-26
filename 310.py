class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        adjList = [set() for _ in range(n)]
        for e in edges:
            adjList[e[0]].add(e[1])
            adjList[e[1]].add(e[0])
        leafNodes = [i for i, l in enumerate(adjList) if len(l) == 1]
        while n > 2:
            newLeaves = []
            for leaf in leafNodes:
                j = adjList[leaf].pop()
                adjList[j].remove(leaf)
                if len(adjList[j]) == 1:
                    newLeaves.append(j)
            n -= len(leafNodes)
            leafNodes = newLeaves
        return leafNodes

