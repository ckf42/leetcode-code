class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        for i in range(m):
            for j in range(1, n):
                if mat[i][j] == 1:
                    mat[i][j] += mat[i][j - 1]
        res = 0
        for j in range(n):
            st = [(0, -1)]
            for i in range(m):
                h = i
                while len(st) != 0 and st[-1][0] >= mat[i][j]:
                    h = st[-1][1]
                    st.pop()
                st.append((mat[i][j], h))
                prevH = i + 1
                for l, h in st[::-1]:
                    res += l * (prevH - h)
                    prevH = h
        return res
