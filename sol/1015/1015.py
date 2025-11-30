from math import gcd

class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k == 1:
            return 1
        if gcd(k, 10) != 1:
            return -1
        n = 1
        r = 1
        while r != 0:
            r = (r * 10 + 1) % k
            n += 1
        return n

