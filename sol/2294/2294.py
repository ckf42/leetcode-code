class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        res = 1
        start = nums[0]
        for x in nums:
            if x - start > k:
                res += 1
                start = x
        return res
