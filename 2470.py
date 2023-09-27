from math import lcm

class Solution:
    def subarrayLCM(self, nums: List[int], k: int) -> int:
        count = 0
        for i in range(len(nums)):
            l = nums[i]
            if l == k:
                count += 1
            elif l > k or k % l != 0:
                continue
            for j in range(i + 1, len(nums)):
                l = lcm(l, nums[j])
                if l == k:
                    count += 1
                elif l > k or k % l != 0:
                    break
        return count
