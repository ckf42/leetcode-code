class Solution:
    def minLength(self, s: str) -> int:
        st = []
        for c in s:
            if len(st) >= 1 and ((st[-1] == 'A' and c == 'B') or (st[-1] == 'C' and c == 'D')):
                st.pop()
            else:
                st.append(c)
        return len(st)
