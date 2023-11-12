from collections import defaultdict, deque

class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        routes = list(frozenset(e) for e in routes if len(e) >= 2)
        n = len(routes)
        edgeDict = defaultdict(list)
        h = deque()
        endRoute = set()
        for i in range(n):
            for j in range(i + 1, n):
                if not routes[i].isdisjoint(routes[j]):
                    edgeDict[i].append(j)
                    edgeDict[j].append(i)
            if source in routes[i]:
                h.append((1, i))
            if target in routes[i]:
                endRoute.add(i)
        if len(endRoute) == 0:
            return -1
        if any(pt[1] in endRoute for pt in h):
            return 1
        visited = set()
        while len(h) != 0:
            currCost, currRoute = h.popleft()
            if currRoute in visited:
                continue
            visited.add(currRoute)
            for nei in edgeDict[currRoute]:
                if nei not in visited:
                    if nei in endRoute:
                        return currCost + 1
                    h.append((currCost + 1, nei))
        return -1
