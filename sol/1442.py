class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        prefix = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix[i] = prefix[i - 1] ^ arr[i - 1]  # [0, e)
        count = 0
        for i in range(n - 1):
            for k in range(i + 1, n):
                if prefix[k + 1] == prefix[i]:
                    count += k - i
        return count

