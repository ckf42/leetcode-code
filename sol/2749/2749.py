class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for count in range(1, (31 if num2 >= 0 else 60) + 1):
            num1 -= num2
            if num1 >= 0 and num1.bit_count() <= count <= num1:
                return count
        return -1
