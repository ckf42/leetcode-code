class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        d = {
            i: v
            for i, v in nums1
        }
        for i, v in nums2:
            d[i] = d.get(i, 0) + v
        return ((k, d[k]) for k in sorted(d.keys()))
