import bisect

class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        n1 = len(nums1)
        n2 = len(nums2)
        lst = [nums1[0] * nums2[0], nums1[0] * nums2[-1], nums1[-1] * nums2[0], nums1[-1] * nums2[-1]]
        offset = min(lst)
        s = 0
        e = max(lst) - offset + 1
        while s < e:
            m = (s + e) // 2
            val = m + offset
            count = 0
            for x in nums1:
                if x == 0:
                    count += n2 if val >= 0 else 0
                elif x > 0:
                    count += bisect.bisect(nums2, val / x)
                else:
                    count += n2 - bisect.bisect_left(nums2, val / x)
            if count < k:
                s = m + 1
            else:
                e = m
        return s + offset
