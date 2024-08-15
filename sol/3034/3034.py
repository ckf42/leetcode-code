class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        n = len(nums)
        p = len(pattern)
        for i in range(n - 1):
            nums[i] = 0 if nums[i] == nums[i + 1] else (1 if nums[i + 1] > nums[i] else -1)
        res = 0
        count = [0] * 2
        realVal = [0] * 2
        for i in range(p):
            if nums[i] != -1:
                count[nums[i]] += 1
            if pattern[i] != -1:
                realVal[pattern[i]] += 1
        if realVal[0] == count[0] and realVal[1] == count[1]:
            res += nums[:p] == pattern
        for i in range(p, n - 1):
            if nums[i] != -1:
                count[nums[i]] += 1
            if nums[i - p] != -1:
                count[nums[i - p]] -= 1
            if realVal[0] == count[0] and realVal[1] == count[1]:
                res += nums[i - p + 1:i + 1] == pattern
        return res
