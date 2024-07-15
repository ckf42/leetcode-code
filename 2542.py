import heapq as hq

class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        n = len(nums1)
        if k == 1:
            return max(x * y for x, y in zip(nums1, nums2))
        indices = list(range(n))
        indices.sort(key=lambda i: nums2[i], reverse=True)
        h = [nums1[indices[i]] for i in range(k - 1)]
        hq.heapify(h)
        sumh = sum(h)
        res = (sumh + nums1[indices[k - 1]]) * nums2[indices[k - 1]]
        for i in range(k, n):
            x = nums1[indices[i - 1]]
            exclude = hq.heappushpop(h, x)
            sumh += x - exclude
            res = max(res, (sumh + nums1[indices[i]]) * nums2[indices[i]])
        return res
