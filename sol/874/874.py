class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        x, y = 0, 0
        diffx, diffy = 0, 1
        maxDist = 0
        obstacles = frozenset((a, b) for (a, b) in obstacles)
        for cmd in commands:
            if cmd == -2:
                diffx, diffy = -diffy, diffx
            elif cmd == -1:
                diffx, diffy = diffy, -diffx
            else:
                for _ in range(cmd):
                    newx = x + diffx
                    newy = y + diffy
                    if (newx, newy) in obstacles:
                        break
                    x, y = newx, newy
                maxDist = max(maxDist, x ** 2 + y ** 2)
        return maxDist
