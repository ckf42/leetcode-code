class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(customers)
        if n == minutes:
            return sum(customers)
        satisfied = sum(c for c, g in zip(customers, grumpy) if g == 0)
        maxGain = 0
        currGain = 0
        for i in range(minutes):
            if grumpy[i] == 1:
                currGain += customers[i]
        maxGain = currGain
        for r in range(minutes, n):
            if grumpy[r] == 1:
                currGain += customers[r]
            if grumpy[r - minutes] == 1:
                currGain -= customers[r - minutes]
            maxGain = max(maxGain, currGain)
        return satisfied + maxGain

