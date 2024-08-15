from bisect import bisect_left

class Solution:
    # https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326308/c-python-dp-binary-search-bit-segment-tree-solutions-picture-explain-o-nlogn
    def lengthOfLIS(self, nums: List[int]) -> int:
        tailPtr = 0
        for x in nums:
            if tailPtr == 0 or x > nums[tailPtr - 1]:
                nums[tailPtr] = x
                tailPtr += 1
            else:
                nums[bisect_left(nums, x, hi=tailPtr)] = x
        return tailPtr
