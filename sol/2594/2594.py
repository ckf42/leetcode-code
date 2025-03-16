class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        ranks.sort()
        s = ranks[0] * (cars // len(ranks)) ** 2
        e = ranks[0] * cars ** 2
        while s < e:
            m = (s + e) // 2
            remain = cars
            for r in ranks:
                remain -= int((m / r) ** 0.5)
                if remain <= 0:
                    break
            if remain <= 0:
                e = m
            else:
                s = m + 1
        return s
