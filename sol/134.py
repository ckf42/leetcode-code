class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        curr = 0
        mingas = float('inf')
        mingasidx = 0
        for i in range(n):
            curr += gas[i] - cost[i]
            if curr <= mingas:  # or < instead?
                mingas = curr
                mingasidx = i
        if curr < 0:
            return -1
        return (mingasidx + 1) % n
