class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        maxScore = nums[k]
        submin = nums[k]
        l = k
        r = k
        while l > 0 or r < len(nums) - 1:
            while l > 0 and nums[l - 1] >= submin:
                l -= 1
            while r < len(nums) - 1 and nums[r + 1] >= submin:
                r += 1
            maxScore = max(maxScore, submin * (r - l + 1))
            if l == 0 and r == len(nums) - 1:
                break
            if l == 0 or (r < len(nums) - 1 and nums[r + 1] > nums[l - 1]):
                r += 1
                submin = min(submin, nums[r])
            else:
                l -= 1
                submin = min(submin, nums[l])
        return maxScore
