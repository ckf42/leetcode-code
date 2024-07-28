class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        h = {0: 0}
        for r in wall:
            l = 0
            for x in r[:-1]:
                l += x
                h[l] = h.get(l, 0) + 1
        return len(wall) - max(h.values())
