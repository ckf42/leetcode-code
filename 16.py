class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        diff = float('inf')
        res = float('inf')
        n = len(nums)
        nums.sort()
        for i in range(n - 2):
            j = i + 1
            k = n - 1
            while j < k:
                tot = nums[i] + nums[j] + nums[k]
                if tot == target:
                    return target
                if (d := abs(tot - target)) < diff:
                    res = tot
                    diff = d
                if tot > target:
                    k -= 1
                else:
                    j += 1
        return res
