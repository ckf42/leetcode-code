class Solution:
    def simplifyPath(self, path: str) -> str:
        st = []
        for comp in path.split('/'):
            if comp == '..':
                if len(st) != 0:
                    st.pop()
            elif comp != '' and comp != '.':
                st.append(comp)
        return '/' + '/'.join(st)
