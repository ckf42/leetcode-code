class Solution:
    def removeDuplicates(self, s: str) -> str:
        st = list()  # deque does not seem to improve runtime
        for c in s:
            if len(st) == 0 or c != st[-1]:
                st.append(c)
            else:
                st.pop()
        return ''.join(st)
