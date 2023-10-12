class Solution:
    modulo: int = int(1e9) + 7
    dparr = dict()

    def dp(self, arrsize: int, cost: int, maxval: int) -> int:
        if arrsize == 0:
            return 0
        if arrsize == 1:
            return 0 if cost != 1 else 1
        if cost > arrsize or cost == 0:
            return 0
        if (arrsize, cost, maxval) not in self.dparr:
            self.dparr[(arrsize, cost, maxval)] = (
                sum(self.dp(arrsize - 1, cost - 1, v)
                    for v in range(1, maxval)) % self.modulo
                + self.dp(arrsize - 1, cost, maxval) * maxval) % self.modulo
        return self.dparr[(arrsize, cost, maxval)]

    def numOfArrays(self, n: int, m: int, k: int) -> int:
        return sum(self.dp(arrsize=n, cost=k, maxval=v)
                   for v in range(1, m + 1)) % self.modulo
