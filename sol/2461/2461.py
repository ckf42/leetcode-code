class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res = 0
        rec = set()
        l = 0
        total = 0
        for r in range(n):
            while nums[r] in rec or len(rec) >= k:
                rec.remove(nums[l])
                total -= nums[l]
                l += 1
            rec.add(nums[r])
            total += nums[r]
            if len(rec) == k:
                res = max(res, total)
        return res
