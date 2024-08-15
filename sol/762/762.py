
class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        return sum((0xa28ac >> i.bit_count()) & 1 for i in range(left, right + 1))
