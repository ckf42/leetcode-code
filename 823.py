class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        m = int(1e9) + 7
        arr.sort()
        dp = {a: 1 for a in arr}
        for i in range(1, len(arr)):
            for j in range(i):
                if arr[j] * arr[j] > arr[i]:
                    break
                if arr[i] % arr[j] == 0 and arr[i] // arr[j] in dp:
                    val = (dp[arr[j]] * dp[arr[i] // arr[j]]) % m
                    if arr[i] != arr[j] * arr[j]:
                        val = (val * 2) % m
                    dp[arr[i]] = (dp[arr[i]] + val) % m
        return sum(dp.values()) % m
