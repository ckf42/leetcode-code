class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        mask = 0
        while operations:
            mask <<= 1
            mask |= operations.pop()
        return chr(((k - 1) & mask).bit_count() % 26 + ord('a'))
