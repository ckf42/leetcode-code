class Solution:
    def makeGood(self, s: str) -> str:
        stack = []
        for c in s:
            if len(stack) == 0 or abs(ord(c) - ord(stack[-1])) != 32:
                stack.append(c)
            elif len(stack) != 0:
                stack.pop()
        return ''.join(stack)
