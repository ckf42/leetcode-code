class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        totalWait = 0
        currTime = 0
        for a, t in customers:
            currTime = max(currTime, a) + t
            totalWait += currTime - a
        return totalWait / len(customers)

