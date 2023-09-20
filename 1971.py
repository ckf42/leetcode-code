from collections import defaultdict

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if source == destination:
            return True
        nbDict = defaultdict(list)
        for edge in edges:
            nbDict[edge[0]].append(edge[1])
            nbDict[edge[1]].append(edge[0])
        visited = set()
        newlyVisited = frozenset((source,))
        while len(newlyVisited) != 0:
            visited.update(newlyVisited)
            newlyVisited = frozenset(
                pt
                for s in newlyVisited
                for pt in nbDict[s]
                if pt not in visited)
            if destination in newlyVisited:
                return True
        return False
