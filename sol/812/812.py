class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        n = len(points)
        return max(
            abs(
                x1 * (y2 - y3)
                + x2 * (y3 - y1)
                + x3 * (y1 - y2)
            ) / 2
            for i, (x1, y1) in enumerate(points)
            for j, (x2, y2) in enumerate(points[i + 1:], start=i + 1)
            for x3, y3 in points[j + 1:]
        )
