from math import gcd

class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        count = 0
        for i in range(len(nums)):
            g = nums[i]
            if g == k:
                count += 1
            elif g % k != 0:
                continue
            for j in range(i + 1, len(nums)):
                g = gcd(g, nums[j])
                if g == k:
                    count += 1
                elif g % k != 0:
                    break
        return count
