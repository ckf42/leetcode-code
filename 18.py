class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        h = dict()
        for i, x in enumerate(nums):
            h[x] = i
        res = []
        i = 0
        while i < n - 3:
            j = i + 1
            while j < n - 2:
                k = j + 1
                while k < n - 1:
                    x = target - nums[i] - nums[j] - nums[k]
                    if x < nums[k]:
                        break
                    if h.get(x, -1) > k:
                        res.append((nums[i], nums[j], nums[k], x))
                    k = h[nums[k]] + 1
                j = h[nums[j]] + 1
            i = h[nums[i]] + 1
        return res
