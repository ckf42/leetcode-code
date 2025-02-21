class Solution:
    def smallestNumber(self, pattern: str) -> str:
        n = len(pattern)
        res = [0] * (n + 1)
        used = [False] * 10
        def fill(i: int) -> bool:
            if i >= n + 1:
                return True
            rg = range(res[i - 1] + 1, 10) if pattern[i - 1] == 'I' else range(res[i - 1] - 1, 0, -1)
            for x in rg:
                if used[x]:
                    continue
                used[x] = True
                res[i] = x
                if fill(i + 1):
                    return True
                used[x] = False
            return False
        for i in range(1, 10):
            res[0] = i
            used[i] = True
            if fill(1):
                break
            used[i] = False
        return ''.join(str(x) for x in res)

