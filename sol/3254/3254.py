class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        res = [-1] * (n - k + 1)
        i = k - 1
        while i > 0 and nums[i - 1] + 1 == nums[i]:
            i -= 1
        if i == 0:
            res[0] = nums[k - 1]
        for j in range(k, n):
            if nums[j] != nums[j - 1] + 1:
                i = j
            if j - i + 1 >= k:
                res[j - k + 1] = nums[j]
        return res
