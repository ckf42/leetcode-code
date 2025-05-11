class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        sum1 = sum(nums1)
        count1 = nums1.count(0)
        sum2 = sum(nums2)
        count2 = nums2.count(0)
        if count1 == 0 == count2:
            return -1 if sum1 != sum2 else sum1
        if count2 == 0:
            return -1 if sum1 + count1 > sum2 else sum2
        if count1 == 0:
            return -1 if sum1 < sum2 + count2 else sum1
        return max(sum1 + count1, sum2 + count2)
