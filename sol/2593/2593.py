class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        marked = [False] * n
        indices = sorted(range(n), key=lambda x: nums[x])
        score = 0
        for i in indices:
            if marked[i]:
                continue
            score += nums[i]
            if i > 0:
                marked[i - 1] = True
            marked[i] = True
            if i < n - 1:
                marked[i + 1] = True
        return score
