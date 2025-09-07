class Solution:
    def sumZero(self, n: int) -> List[int]:
        if n == 2:
            return [1, -1]
        res = list(range(n - 1))
        res.append(-(n - 1) * (n - 2) // 2)
        return res

