import heapq as hq

class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.n = n
        self.edgeDict = list(list() for _ in range(n))
        for e in edges:
            self.addEdge(e)

    def addEdge(self, edge: List[int]) -> None:
        self.edgeDict[edge[0]].append((edge[1], edge[2]))

    def shortestPath(self, node1: int, node2: int) -> int:
        h = [(0, node1)]
        visited = list(False for _ in range(self.n))
        while len(h) != 0:
            currCost, currNode = hq.heappop(h)
            if visited[currNode]:
                continue
            if currNode == node2:
                return currCost
            visited[currNode] = True
            for nei, cost in self.edgeDict[currNode]:
                if not visited[nei]:
                    hq.heappush(h, (currCost + cost, nei))
        return -1


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)
