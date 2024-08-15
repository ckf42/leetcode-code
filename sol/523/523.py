class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if n < 2:
            return False
        prefix = 0
        d = {0: -1}
        for i in range(n):
            prefix = (prefix + nums[i]) % k
            if prefix not in d:
                d[prefix] = i
            elif d[prefix] != i - 1:
                return True
        return False
