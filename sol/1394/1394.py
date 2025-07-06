class Solution:
    def findLucky(self, arr: List[int]) -> int:
        freq = dict()
        for i in arr:
            freq[i] = freq.get(i, 0) + 1
        res = -1
        for k, v in freq.items():
            if k == v:
                res = max(res, k)
        return res
