class Solution:
    def search(self, nums: List[int], target: int) -> int:
        s = 0
        e = len(nums) - 1
        while s <= e:
            m = (s + e) // 2
            if nums[m] == target:
                return m
            isOnLeft = nums[s] <= nums[m]
            isSmaller = target < nums[m]
            if isOnLeft:
                if isSmaller:
                    if target == nums[s]:
                        return s
                    elif target < nums[s]:
                        s = m + 1
                    else:
                        e = m - 1
                else:
                    s = m + 1
            else:
                if isSmaller:
                    e = m - 1
                else:
                    if target == nums[e]:
                        return e
                    elif target < nums[e]:
                        s = m + 1
                    else:
                        e = m - 1
        return -1
