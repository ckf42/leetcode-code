class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        n, m = len(matrix), len(matrix[0])
        res = 0
        proj = [0] * m
        for i in range(n):
            for j in range(m):
                proj[j] = 0 if matrix[i][j] == '0' else (proj[j] + 1)
            st = []
            for x in proj:
                if x == 0:
                    for i, p in enumerate(st):
                        res = max(res, p * (len(st) - i))
                    st.clear()
                else:
                    ptr = len(st) - 1
                    while ptr >= 0 and st[ptr] > x:
                        res = max(res, st[ptr] * (len(st) - ptr))
                        st[ptr] = x
                        ptr -= 1
                    st.append(x)
            for i, p in enumerate(st):
                res = max(res, p * (len(st) - i))
        return res
