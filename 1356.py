class Solution:
    def key(self, a: int) -> int:
        return a + 10001 * a.bit_count()

    def sortByBits(self, arr: List[int]) -> List[int]:
        return sorted(arr, key=self.key)
