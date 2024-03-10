class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return frozenset(nums1).intersection(nums2)
