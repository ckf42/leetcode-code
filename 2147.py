class Solution:
    M = int(1e9) + 7

    def numberOfWays(self, corridor: str) -> int:
        plants = list()
        lastGroupEnd = -1
        for i, item in enumerate(corridor):
            if item == 'P':
                continue
            if lastGroupEnd is None:
                lastGroupEnd = i
            else:
                plantCount = i - lastGroupEnd - 1
                if plantCount != 0:
                    plants.append(plantCount)
                lastGroupEnd = None
        if lastGroupEnd is None or lastGroupEnd == -1:
            return 0
        s = 0
        if corridor[0] == 'P':
            s += 1
        res = 1
        for p in plants[s:]:
            res = (res * (p + 1)) % self.M
        return res

