class Solution:
    def largestGoodInteger(self, num: str) -> str:
        res = ""
        for i in range(10):
            d = chr(ord('0') + i) * 3
            if d in num:
                res = d
        return res
