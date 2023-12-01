class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        m = n
        while m:
            m >>= 1
            n ^= m
        return n
