from collections import deque

class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        mst = deque()
        for j in range(len(nums)):
            if len(mst) != 0:
                nums[j] += nums[mst[0]]
            while len(mst) != 0 and mst[0] <= j - k:
                mst.popleft()
            while len(mst) != 0 and nums[mst[-1]] < nums[j]:
                mst.pop()
            if nums[j] > 0:
                mst.append(j)
        return max(nums)
