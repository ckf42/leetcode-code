class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        ans = [0] * n
        st = []
        for i, t in enumerate(temperatures):
            while len(st) != 0 and t > temperatures[st[-1]]:
                idx = st.pop()
                ans[idx] = i - idx
            st.append(i)
        return ans
