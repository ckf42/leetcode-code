class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        charList = list(s)
        unmatchedOpenParenIndices = []
        dep = 0
        for i, c in enumerate(s):
            if c == '(':
                dep += 1
                unmatchedOpenParenIndices.append(i)
            elif c == ')':
                if dep == 0:
                    charList[i] = ''
                else:
                    unmatchedOpenParenIndices.pop()
                    dep -= 1
        for i in unmatchedOpenParenIndices:
            charList[i] = ''
        return ''.join(charList)
