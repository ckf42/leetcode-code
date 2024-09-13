class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        prefix = [0] * (n + 1)
        prefix[1] = arr[0]
        for i in range(2, n + 1):
            prefix[i] = prefix[i - 1] ^ arr[i - 1]
        return (prefix[l] ^ prefix[r + 1] for l, r in queries)
