class Solution:
    def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
        n = len(plants)
        a = 0
        b = n - 1
        wa = capacityA
        wb = capacityB
        refill = 0
        while a < b:
            if plants[a] > wa:
                refill += 1
                wa = capacityA
            wa -= plants[a]
            a += 1
            if plants[b] > wb:
                refill += 1
                wb = capacityB
            wb -= plants[b]
            b -= 1
        if a == b:
            refill += (plants[a] > max(wa, wb))
        return refill
