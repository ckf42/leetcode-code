class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        h = dict()
        nums.sort()
        for i, x in enumerate(nums):
            h[x] = i
        res = []
        n = len(nums)
        i = 0
        while i < n - 2:
            x = nums[i]
            if x > 0:
                break
            j = i + 1
            while j < n - 1:
                y = nums[j]
                z = -(x + y)
                if z < y:
                    break
                if h.get(z, -1) > j:
                    res.append((x, y, z))
                j = h[y] + 1
            i = h[x] + 1
        return res
