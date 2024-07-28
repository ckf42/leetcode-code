class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        n = len(s)
        oneCount = sum(c == '1' for c in s)
        return '1' * (oneCount - 1) + '0' * (n - oneCount) + '1'
