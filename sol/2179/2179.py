class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        loc2 = [0] * n
        for i, x in enumerate(nums2):
            loc2[x] = i
        fTree = [0] * (n + 1)
        res = 0
        for j in range(0, n):
            y = nums1[j]
            j2 = loc2[y]
            # xCount = sum(1 for i in range(j) if loc2[nums1[i]] < j2)
            xCount = 0
            idx = j2 + 1
            while idx > 0:
                xCount += fTree[idx]
                idx -= idx & -idx
            idx = j2 + 1
            while idx <= n:
                fTree[idx] += 1
                idx += idx & -idx
            zCount = n - 1 - j2 - j + xCount
            res += xCount * zCount
        return res
