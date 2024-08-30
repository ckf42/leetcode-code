class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m = len(grid1)
        n = len(grid1[0])
        res = 0
        for i in range(m):
            for j in range(n):
                if grid2[i][j] == 0 or grid1[i][j] == 0:
                    continue
                st = [(i, j)]
                allCovered = True
                while len(st) != 0:
                    a, b = st.pop()
                    if grid2[a][b] == 0:
                        continue
                    grid2[a][b] = 0
                    if grid1[a][b] == 0:
                        allCovered = False
                    if a > 0:
                        st.append((a - 1, b))
                    if a < m - 1:
                        st.append((a + 1, b))
                    if b > 0:
                        st.append((a, b - 1))
                    if b < n - 1:
                        st.append((a, b + 1))
                if allCovered:
                    res += 1
        return res
