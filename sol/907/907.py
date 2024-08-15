class Solution:
    m = 10 ** 9 + 7
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n = len(arr)
        memo = [0] * n
        memo[0] = arr[0]
        st = [0]
        res = arr[0]
        for i in range(1, n):
            while len(st) != 0 and arr[st[-1]] > arr[i]:
                st.pop()
            if len(st) == 0:
                memo[i] = (i + 1) * arr[i]
            else:
                j = st[-1]
                memo[i] = memo[j] + (i - j) * arr[i]
            st.append(i)
            res = (res + memo[i]) % self.m
        return res
