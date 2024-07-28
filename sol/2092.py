import heapq as hq
from collections import defaultdict

class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        edges = defaultdict(list)
        for x, y, t in meetings:
            edges[x].append((t, y))
            edges[y].append((t, x))
        knower = set()
        h = [(0, 0), (0, firstPerson)]
        while len(h) != 0:
            t0, x = hq.heappop(h)
            if x in knower:
                continue
            knower.add(x)
            for t, y in edges[x]:
                if t >= t0 and y not in knower:
                    hq.heappush(h, (t, y))
        return knower
