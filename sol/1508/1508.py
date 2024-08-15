class Solution:
    m = 10 ** 9 + 7
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        for i in range(1, n):
            nums[i] += nums[i - 1]
        lst = nums
        for i in range(n - 1):
            for j in range(i + 1, n):
                lst.append(nums[j] - nums[i])
        lst.sort()
        return sum(lst[left - 1 : right]) % self.m
