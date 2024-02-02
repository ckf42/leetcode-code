class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token in '+-*/':
                opnd2 = stack.pop()
                opnd1 = stack.pop()
                if token == '+':
                    stack.append(opnd1 + opnd2)
                elif token == '-':
                    stack.append(opnd1 - opnd2)
                elif token == '*':
                    stack.append(opnd1 * opnd2)
                elif token == '/':
                    stack.append(int(opnd1 / opnd2))
            else:
                stack.append(int(token))
        return stack[-1]
