class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        prefix = 0
        while prefix < n - 1 and arr[prefix] <= arr[prefix + 1]:
            prefix += 1
        i = prefix
        res = prefix + 1
        prev = arr[n - 1] + 1
        for j in range(n - 1, prefix, -1):
            if arr[j] > prev:
                break
            prev = arr[j]
            while i >= 0 and arr[i] > arr[j]:
                i -= 1
            res = max(res, n + 1 + i - j)
        return n - res
