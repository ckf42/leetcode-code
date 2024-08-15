class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        n = len(nums)
        memo = [0] * n
        memo[0] = nums[0]
        st = [0]
        res = 0
        for i in range(1, n):
            while len(st) != 0 and nums[st[-1]] < nums[i]:
                st.pop()
            if len(st) == 0:
                memo[i] = (i + 1) * nums[i]
            else:
                j = st[-1]
                memo[i] = memo[j] + (i - j) * nums[i]
            st.append(i)
            res += memo[i]
        st = [0]
        for i in range(1, n):
            while len(st) != 0 and nums[st[-1]] > nums[i]:
                st.pop()
            if len(st) == 0:
                memo[i] = (i + 1) * nums[i]
            else:
                j = st[-1]
                memo[i] = memo[j] + (i - j) * nums[i]
            st.append(i)
            res -= memo[i]
        return res
