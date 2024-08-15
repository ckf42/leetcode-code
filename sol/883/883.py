class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        return sum(sum(x != 0 for x in r) for r in grid) \
                + sum(max(r) for r in grid) \
                + sum(max(c) for c in zip(*grid))
