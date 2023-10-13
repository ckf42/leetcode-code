class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x, y = 0, 0
        idx = 1
        directions = ((1, 0), (0, 1), (-1, 0), (0, -1))
        for inst in instructions:
            if inst == 'G':
                x += directions[idx][0]
                y += directions[idx][1]
            elif inst == 'L':
                idx = (idx + 1) & 3
            else:
                idx = (idx + 3) & 3
        return (x == 0 and y == 0) or idx != 1
