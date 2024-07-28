class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        sgn = "" if num >= 0 else "-"
        if num < 0:
            num = -num
        digits = list()
        while num != 0:
            num, r = divmod(num, 7)
            digits.append(str(r))
        return sgn + "".join(digits[::-1])
