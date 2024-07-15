import bisect

class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        return bisect.bisect_left(
            range(1, max(quantities) + 1),
            True,
            key=lambda q: sum((x + q - 1) // q for x in quantities) <= n) + 1
