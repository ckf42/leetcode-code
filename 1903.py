class Solution:
    def largestOddNumber(self, num: str) -> str:
        ptr = len(num) - 1
        oddDig = frozenset('13579')
        while ptr >= 0 and num[ptr] not in oddDig:
            ptr -= 1
        return num[:ptr + 1]
