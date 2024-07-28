class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if num.count('0') + k >= len(num):
            return '0'
        st = []
        delCount = 0
        for c in num:
            while delCount < k and len(st) > 0 and c < st[-1]:
                st.pop()
                delCount += 1
            st.append(c)
        for _ in range(k - delCount):
            st.pop()
        res = ''.join(st).lstrip('0')
        if len(res) == 0:
            return '0'
        else:
            return res
