class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        res = [0] * n
        val = 1
        for i in range(n):
            res[i] = val
            if (p := val * 10) <= n:
                val = p
            else:
                while val % 10 == 9 or val + 1 > n:
                    val //= 10
                val += 1
        return res
