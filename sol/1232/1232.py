class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if len(coordinates) == 2:
            return True
        dy = coordinates[1][1] - coordinates[0][1]
        dx = coordinates[1][0] - coordinates[0][0]
        for i in range(2, len(coordinates)):
            if (coordinates[i][1] - coordinates[0][1]) * dx != dy * (coordinates[i][0] - coordinates[0][0]):
                return False
        return True
