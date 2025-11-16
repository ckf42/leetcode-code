class Solution:
    def minOperations(self, nums: List[int]) -> int:
        res = 0
        st = [0]
        for x in nums:
            while st[-1] > x:
                res += 1
                st.pop()
            if st[-1] != x:
                st.append(x)
        res += len(st) - 1
        return res
