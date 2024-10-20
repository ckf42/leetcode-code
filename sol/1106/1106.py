class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        ptr = 0
        def evalExpr() -> bool:
            nonlocal ptr
            c = expression[ptr]
            if c in 'tf':
                ptr += 1
                return c == 't'
            elif c == '!':
                ptr += 2
                res = evalExpr()
                ptr += 1
                return not res
            elif c == '&':
                res = True
                ptr += 1
                while expression[ptr] != ')':
                    ptr += 1
                    res &= evalExpr()
                ptr += 1
                return res
            elif c == '|':
                res = False
                ptr += 1
                while expression[ptr] != ')':
                    ptr += 1
                    res |= evalExpr()
                ptr += 1
                return res
            else:
                print('Unreachable branch')
                return False
        return evalExpr()
