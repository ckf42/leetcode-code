class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        n = len(obstacles) - 1
        jumps = 0
        frogPos = 0b0100
        for i in range(1, n + 1):
            frogPos &= 0b1111 ^ (1 << obstacles[i])
            if frogPos == 0b0000:
                jumps += 1
                frogPos = 0b1110 & (0b1111 ^ ((1 << obstacles[i]) | (1 << obstacles[i - 1])))
        return jumps
