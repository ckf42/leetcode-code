from itertools import permutations as perm

class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        l = len(str(n))
        def solve(state, nextChar, opt):
            if len(state) > l + 1:
                return opt
            if len(state) != 0 and int(state[::-1]) > n:
                for p in perm(state, len(state)):
                    x = int(''.join(p))
                    if x <= n:
                        continue
                    if x < opt:
                        opt = x
            for cand in range(nextChar, min(9, l + 1 - len(state)) + 1):
                opt = min(opt, solve(state + str(cand) * cand, cand + 1, opt))
            return opt
        return solve('', 1, 1224444)
