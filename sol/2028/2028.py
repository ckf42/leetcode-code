class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        residual = (m + n) * mean - sum(rolls)
        if residual > 6 * n or residual < n:
            return []
        q, r = divmod(residual, n)
        return [q + 1] * r + [q] * (n - r)
