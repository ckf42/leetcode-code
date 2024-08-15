from collections import deque

class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        recentMaxIndices = deque()
        for j in range(len(nums)):
            if len(recentMaxIndices) != 0:
                nums[j] += nums[recentMaxIndices[0]]
            while len(recentMaxIndices) != 0:
                if j - recentMaxIndices[0] >= k:
                    recentMaxIndices.popleft()
                elif nums[recentMaxIndices[-1]] < nums[j]:
                    recentMaxIndices.pop()
                else:
                    break
            if nums[j] > 0:
                recentMaxIndices.append(j)
        return max(nums)
