from collections import Counter

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        c = Counter(nums1)
        res = []
        for x in nums2:
            if c[x] > 0:
                res.append(x)
                c[x] -= 1
        return res
