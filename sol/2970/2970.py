class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 1
        isPre = [False] * n  # [0, i)
        isPre[0] = True
        isPre[1] = True
        for i in range(2, n):
            if nums[i - 1] <= nums[i - 2]:
                break
            isPre[i] = True
        isPost = [False] * n  # (j, n - 1]
        isPost[n - 1] = True
        isPost[n - 2] = True
        for i in range(n - 3, -1, -1):
            if nums[i + 1] >= nums[i + 2]:
                break
            isPost[i] = True
        return sum(
            i == 0 or j == n - 1 or nums[i - 1] < nums[j + 1]
            for i in range(n)
            for j in range(i, n)
            if isPre[i] and isPost[j]
        )
