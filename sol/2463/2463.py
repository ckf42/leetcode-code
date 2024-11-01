class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        n = len(robot)
        m = len(factory)
        robot.sort()
        fidx = sorted(range(m), key=lambda i: factory[i][0])
        memo = [0] * (n + 1)
        factCount = 0
        for f in range(m - 1, -1, -1):
            floc = factory[fidx[f]][0]
            for _ in range(factory[fidx[f]][1]):
                if factCount < n:
                    memo[n - 1 - factCount] = memo[n - factCount] + abs(robot[n - 1 - factCount] - floc)
                else:
                    memo[0] = min(memo[0], memo[1] + abs(robot[0] - floc))
                for r in range(max(1, n - factCount), n):
                    memo[r] = min(memo[r], memo[r + 1] + abs(robot[r] - floc))
                factCount += 1
        return memo[0]
