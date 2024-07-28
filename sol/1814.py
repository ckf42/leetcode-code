class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        m = int(1e9) + 7
        counter = dict()
        for n in nums:
            k = n - int(str(n)[::-1])
            counter[k] = counter.get(k, 0) + 1
        res = 0
        for v in counter.values():
            res = (res + v * (v - 1) // 2) % m
        return res

