class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def gen(remainOpen, remainClose, prefix):
            if remainOpen == 0:
                res.append(prefix + ')' * remainClose)
                return
            if remainOpen > 0:
                gen(remainOpen - 1, remainClose + 1, prefix + '(')
            if remainClose > 0:
                gen(remainOpen, remainClose - 1, prefix + ')')
        gen(n, 0, "")
        return res
