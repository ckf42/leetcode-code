from math import gcd

class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        res = []
        for x in nums:
            while len(res) != 0 and (g := gcd(x, res[-1])) != 1:
                x = x // g * res.pop()
            res.append(x)
        return res
