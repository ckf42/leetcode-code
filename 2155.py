class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        res = [0]
        score = 0
        high = score
        for i, x in enumerate(nums):
            if x == 0:
                score += 1
            else:
                score -= 1
            if score > high:
                high = score
                res.clear()
            if score == high:
                res.append(i + 1)
        return res
