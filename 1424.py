from collections import deque

class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        q = deque()
        q.append((0, 0))
        while len(q) != 0:
            i, j = q.popleft()
            yield nums[i][j]
            if j == 0 and i < len(nums) - 1:
                q.append((i + 1, 0))
            if j < len(nums[i]) - 1:
                q.append((i, j + 1))
