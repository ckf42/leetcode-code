class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        m = 2 * n - 1
        res = [0] * m
        def fill(i, used):
            nonlocal res
            if i == m:
                return True
            if res[i] != 0:
                return fill(i + 1, used)
            for v in range(n, 1, -1):
                if used[v] or i + v >= m or res[i + v] != 0:
                    continue
                res[i] = v
                res[i + v] = v
                used[v] = True
                if fill(i + 1, used):
                    return True
                res[i] = 0
                res[i + v] = 0
                used[v] = False
            if not used[1]:
                res[i] = 1
                used[1] = True
                if fill(i + 1, used):
                    return True
                res[i] = 0
                used[1] = False
            return False
        fill(0, [False] * (n + 1))
        return res

