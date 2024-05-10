class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        res = 0
        for i in range(k):
            diff = happiness[i] - i
            if diff > 0:
                res += diff
            else:
                break
        return res
