from collections import defaultdict

class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        count = defaultdict(int)
        for arr in (nums1, nums2, nums3):
            for x in frozenset(arr):
                count[x] += 1
        return (k for k, v in count.items() if v >= 2)
