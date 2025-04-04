class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        n = len(weights)
        if n == k or k == 1:
            return 0
        indexVal = sorted([weights[i] + weights[i + 1] for i in range(n - 1)])
        return sum(indexVal[n - k:]) - sum(indexVal[:k - 1])
