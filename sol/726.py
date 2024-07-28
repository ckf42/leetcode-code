class Solution:
    def countOfAtoms(self, formula: str) -> str:
        st = [dict()]
        n = len(formula)
        ptr = 0
        while ptr < n:
            if formula[ptr] == '(':
                st.append(dict())
                ptr += 1
            elif formula[ptr] == ')':
                ptr += 1
                s = ptr
                while ptr < n and formula[ptr].isnumeric():
                    ptr += 1
                count = 1
                if ptr != s:
                    count = int(formula[s:ptr])
                ctx = st.pop()
                for k, v in ctx.items():
                    st[-1][k] = st[-1].get(k, 0) + v * count
            else:
                s = ptr
                ptr += 1
                while ptr < n and formula[ptr].islower():
                    ptr += 1
                name = formula[s:ptr]
                s = ptr
                while ptr < n and formula[ptr].isnumeric():
                    ptr += 1
                count = 1
                if ptr != s:
                    count = int(formula[s:ptr])
                st[-1][name] = st[-1].get(name, 0) + count
        return ''.join(k + (str(st[-1][k]) if st[-1][k] != 1 else '') for k in sorted(st[-1].keys()))
