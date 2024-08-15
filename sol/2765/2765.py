class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        maxLen = -1
        sidx = 0
        while True:
            while sidx < len(nums) - 1 and nums[sidx + 1] != nums[sidx] + 1:
                sidx += 1
            if sidx == len(nums) - 1:
                break
            eidx = sidx + 1
            compareZero = True
            s0, s1 = nums[sidx], nums[eidx]
            while eidx < len(nums) - 1 and nums[eidx + 1] == (s0 if compareZero else s1):
                eidx += 1
                compareZero = not compareZero
            maxLen = max(maxLen, eidx + 1 - sidx)
            if eidx == len(nums) - 1:
                break
            sidx = eidx
        return maxLen


