import itertools

class Solution:
    res = {1: '1'}
    def compute(self, n: int) -> None:
        if n not in self.res:
            if n - 1 not in self.res:
                self.compute(n - 1)
            self.res[n] = ''.join(
                    str(len(tuple(g))) + str(k)
                    for k, g in itertools.groupby(self.res[n - 1]))

    def countAndSay(self, n: int) -> str:
        if n not in self.res:
            self.compute(n)
        return self.res[n]
