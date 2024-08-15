import heapq as hq

class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        h = []
        requiredBricks = 0
        for i in range(len(heights) - 1):
            jump = heights[i + 1] - heights[i]
            if jump <= 0:
                continue
            if len(h) < ladders:
                hq.heappush(h, jump)
            elif ladders == 0 or h[0] >= jump:
                requiredBricks += jump
            else:
                requiredBricks += hq.heapreplace(h, jump)
            if requiredBricks > bricks:
                return i
        return len(heights) - 1

