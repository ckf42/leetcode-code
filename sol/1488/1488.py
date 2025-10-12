class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n = len(rains)
        res = [None] * n
        nextVacant = [n] * n
        spot = n
        for i in range(n - 1, -1, -1):
            nextVacant[i] = spot
            if rains[i] == 0:
                spot = i
                res[i] = 0
            else:
                res[i] = -1
        fillDay = dict()
        for d, target in enumerate(rains):
            if target == 0:
                continue
            r = fillDay.get(target, -1)
            if r != -1:
                spot = nextVacant[r]
                while spot < d and res[spot] != 0:
                    spot = nextVacant[spot]
                if spot < d:
                    nextVacant[nextVacant[r]] = nextVacant[spot]
                    res[spot] = target
                else:
                    return []
            fillDay[target] = d
        for i in range(n):
            if res[i] == 0:
                res[i] = 1
        return res
