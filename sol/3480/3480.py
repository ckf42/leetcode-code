class Solution:
    def maxSubarrays(self, n: int, conflictingPairs: List[List[int]]) -> int:
        m = len(conflictingPairs)
        for i, (a, b) in enumerate(conflictingPairs):
            if b < a:
                conflictingPairs[i] = [b, a]
        conflictingPairs.sort(key=lambda pr: pr[0], reverse=True)
        prIdx = 0
        minB = [n + 1, n + 1]
        minBIdx = m
        ignoreGain = [0] * (m + 1)
        total = 0
        for i in range(n, 0, -1):
            while prIdx < m and (pr := conflictingPairs[prIdx])[0] >= i:
                if pr[1] < minB[0]:
                    minB[0], minB[1] = pr[1], minB[0]
                    minBIdx = prIdx
                elif pr[1] < minB[1]:
                    minB[1] = pr[1]
                prIdx += 1
            total += minB[0] - i
            ignoreGain[minBIdx] += minB[1] - minB[0]
        return total + max(ignoreGain[:m])
