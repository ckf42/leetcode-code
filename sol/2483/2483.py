class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        bestTime = n
        bestPen = n
        p = n
        for i in range(n - 1, -1, -1):
            if customers[i] == 'Y':
                p += 1
            else:
                p -= 1
                if p <= bestPen:
                    bestPen = p
                    bestTime = i
        return bestTime
