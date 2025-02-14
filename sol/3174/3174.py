class Solution:
    def clearDigits(self, s: str) -> str:
        charSt = []
        for x in s:
            if x.isalpha():
                charSt.append(x)
            else:  # isnum
                charSt.pop()
        return ''.join(charSt)
