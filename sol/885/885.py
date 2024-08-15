class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        tot = rows * cols
        i, j = rStart, cStart
        res = [[i, j]]
        l = 1
        while len(res) < tot:
            if 0 <= i < rows:
                for step in range(1, l + 1):
                    if 0 <= j + step < cols:
                        res.append((i, j + step))
            j += l
            if 0 <= j < cols:
                for step in range(1, l + 1):
                    if 0 <= i + step < rows:
                        res.append((i + step, j))
            i += l
            l += 1
            if 0 <= i < rows:
                for step in range(1, l + 1):
                    if 0 <= j - step < cols:
                        res.append((i, j - step))
            j -= l
            if 0 <= j < cols:
                for step in range(1, l + 1):
                    if 0 <= i - step < rows:
                        res.append((i - step, j))
            i -= l
            l += 1
        return res
