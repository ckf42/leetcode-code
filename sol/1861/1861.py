class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m = len(box)
        n = len(box[0])
        res = [['.'] * m for _ in range(n)]
        for i in range(m):
            ptr = n - 1
            for j in range(n - 1, -1, -1):
                if box[i][j] == '#':
                    box[i][j] = '.'
                    res[ptr][m - 1 - i] = '#'
                    ptr -= 1
                elif box[i][j] == '*':
                    res[j][m - 1 - i] = '*'
                    ptr = j - 1
        return res
