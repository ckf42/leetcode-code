class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        res = [0] * n
        if k == 0:
            return res
        if k > 0:
            for i in range(1, k + 1):
                res[0] += code[i]
            e = k
            for i in range(1, n):
                e += 1
                res[i] = res[i - 1] - code[i] + code[e % n]
        else:
            k = -k
            for i in range(1, k + 1):
                res[0] += code[n - i]
            e = -k
            for i in range(1, n):
                res[i] = res[i - 1] + code[i - 1] - code[e % n]
                e += 1
        return res
