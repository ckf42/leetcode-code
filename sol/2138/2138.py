class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        n = len(s)
        q, r = divmod(n, k)
        res = [s[i * k:(i + 1) * k] for i in range(q)]
        if r != 0:
            res.append(s[-r:] + fill * (k - r))
        return res
