class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        res = 0
        for k in range(2, n):
            if nums[0] + nums[1] > nums[k]:
                res += k * (k - 1) // 2
                continue
            i = 0
            for j in range(k - 1, 0, -1):
                while i < j and nums[i] <= nums[k] - nums[j]:
                    i += 1
                if i == j:
                    break
                res += j - i
        return res
