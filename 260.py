class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        a = 0
        for n in nums:
            a ^= n
        b = a & -a
        a = 0
        c = 0
        for n in nums:
            if n & b:
                a ^= n
            else:
                c ^= n
        return [a, c]
