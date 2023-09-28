class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums = sorted((v, i) for i, v in enumerate(nums))
        i = 0
        j = len(nums) - 1
        while i < j:
            s = nums[i][0] + nums[j][0]
            if s == target:
                return nums[i][1], nums[j][1]
            elif s > target:
                j -= 1
            else:
                i += 1
