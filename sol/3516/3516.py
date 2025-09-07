class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        w = abs(x - z) - abs(y - z)
        if w == 0:
            return 0
        if w > 0:
            return 2
        return 1
