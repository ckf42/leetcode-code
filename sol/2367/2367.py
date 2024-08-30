class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        n = len(nums)
        d = {nums[0], nums[1]}
        res = 0
        for k in range(2, n):
            x = nums[k]
            if x - diff in d and x - 2 * diff in d:
                res += 1
            d.add(x)
        return res
