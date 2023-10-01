from collections import deque

class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        lst = deque(maxlen=len(nums))
        for val, idx in zip(nums, index):
            lst.insert(idx, val)
        return lst
