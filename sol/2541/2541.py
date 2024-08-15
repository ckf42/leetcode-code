class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if k == 0:
            return 0 if nums1 == nums2 else -1
        tot = 0
        count = 0
        for x, y in zip(nums1, nums2):
            d = x - y
            q, r = divmod(d, k)
            if r != 0:
                return -1
            tot += q
            if q <= 0:
                continue
            count += q
        return count if tot == 0 else -1
