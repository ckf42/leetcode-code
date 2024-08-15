class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        d = 1
        for i in range(1, n):
            d *= i
        cont = [i for i in range(1, n + 1)]
        res = ""
        for i in range(n - 1, 0, -1):
            res += str(cont.pop((k - 1) // d))
            k %= d
            d //= i
        return res + str(cont[0])
