class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        n = len(edges)
        d1 = [n + 1] * n
        dist = 0
        visited = [False] * n
        while node1 != -1 and not visited[node1]:
            visited[node1] = True
            d1[node1] = dist
            node1 = edges[node1]
            dist += 1
        res = -1
        minDist = n + 1
        dist = 0
        visited = [False] * n
        while node2 != -1 and not visited[node2]:
            visited[node2] = True
            r = max(d1[node2], dist)
            if r < minDist or (r == minDist and node2 < res):
                res = node2
                minDist = r
            dist += 1
            node2 = edges[node2]
        return res
