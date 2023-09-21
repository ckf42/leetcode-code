class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        xCoor = list(pt[0] for pt in points)
        xCoor.sort()
        return max(xCoor[i] - xCoor[i - 1] for i in range(1, len(xCoor)))
