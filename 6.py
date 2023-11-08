class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        m = 2 * numRows - 2
        return ''.join(s[gpStart + ptr]
            for r in range(numRows)
            for gpStart in range(0, len(s), m)
            for ptr in ((r, m - r) if 0 < r < m - r else (r,))
            if gpStart + ptr < len(s))

