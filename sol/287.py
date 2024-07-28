class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        tort, hare = nums[0], nums[nums[0]]
        while tort != hare:
            tort = nums[tort]
            hare = nums[nums[hare]]
        tort = 0
        while tort != hare:
            tort = nums[tort]
            hare = nums[hare]
        return tort
