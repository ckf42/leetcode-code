from functools import cache

class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        @cache
        def dp(l1, l2):
            if l1 < 0 or l2 < 0:
                return -float('inf')
            return max(
                nums1[l1] * nums2[l2] + max(0, dp(l1 - 1, l2 - 1)),
                dp(l1 - 1, l2),
                dp(l1, l2 - 1)
            )

        return dp(len(nums1) - 1, len(nums2) - 1)
