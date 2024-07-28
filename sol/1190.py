class Solution:
    def reverseParentheses(self, s: str) -> str:
        st = [[]]
        for c in s:
            if c == '(':
                st.append([])
            elif c != ')':
                st[-1].append(c)
            else:
                buff = st.pop()
                st[-1].extend(buff[::-1])
        return ''.join(st[-1])
