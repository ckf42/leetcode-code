import bisect

class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        n = len(position)
        position.sort()
        r = position[-1] - position[0] + 1
        l = 1
        while l < r:
            p = (l + r) // 2
            isPlaced = True
            lastBucket = 0
            for _ in range(m - 1):
                lastBucket = bisect.bisect_left(position, position[lastBucket] + p, lastBucket)
                if lastBucket == n:
                    isPlaced = False
                    break
            if isPlaced:
                l = p + 1
            else:
                r = p
        return r - 1
