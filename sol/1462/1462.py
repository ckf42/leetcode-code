from collections import defaultdict, deque

class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        edges = defaultdict(list)
        indeg = defaultdict(int)
        for a, b in prerequisites:
            edges[a].append(b)
            indeg[b] += 1
        buff = deque([a for a in range(numCourses) if indeg[a] == 0])
        req = [set() for _ in range(numCourses)]
        while len(buff) != 0:
            x = buff.popleft()
            for nb in edges[x]:
                req[nb].update(req[x])
                req[nb].add(x)
                indeg[nb] -= 1
                if indeg[nb] == 0:
                    buff.append(nb)
        return [a in req[b] for a, b in queries]
