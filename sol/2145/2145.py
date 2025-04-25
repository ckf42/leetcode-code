class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        n = len(differences)
        orig = [0] * (n + 1)
        for i, diff in enumerate(differences):
            orig[i + 1] = orig[i] + diff
        return max(0, upper - lower - max(orig) + min(orig) + 1)
