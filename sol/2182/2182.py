class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord('a')] += 1
        st = sorted(((chr(i + ord('a')), f) for i, f in enumerate(freq) if f != 0))
        res = ""
        while len(st) != 0:
            c, f = st.pop()
            take = min(f, repeatLimit)
            res += c * take
            f -= take
            if f != 0 and len(st) != 0:
                cc, ff = st.pop()
                res += cc
                if ff != 1:
                    st.append((cc, ff - 1))
                st.append((c, f))
        return res
