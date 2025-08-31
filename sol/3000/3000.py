class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        diag2 = 0
        area = 0
        for a, b in dimensions:
            if (d := a * a + b * b) > diag2:
                diag2 = d
                area = a * b
            elif d == diag2:
                area = max(area, a * b)
        return area
