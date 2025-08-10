class Solution:
    TARGET = tuple(''.join(sorted(str(2 ** p))) for p in range(30))
    def reorderedPowerOf2(self, n: int) -> bool:
        return ''.join(sorted(str(n))) in self.TARGET
