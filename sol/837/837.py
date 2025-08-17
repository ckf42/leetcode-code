class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k - 1 + maxPts <= n:
            return 1
        prob = [0] * (k + maxPts)
        for i in range(k, n + 1):
            prob[i] = 1
        prob[k - 1] = (n + 1 - k) / maxPts
        for i in range(k - 2, -1, -1):
            prob[i] = prob[i + 1] + (prob[i + 1] - prob[i + maxPts + 1]) / maxPts
        return prob[0]
