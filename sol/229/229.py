class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        items = [None, None]
        votes = [0, 0]
        for n in nums:
            if n == items[0]:
                votes[0] += 1
            elif n == items[1]:
                votes[1] += 1
            elif votes[0] == 0:
                items[0] = n
                votes[0] = 1
            elif votes[1] == 0:
                items[1] = n
                votes[1] = 1
            else:
                votes[0] -= 1
                votes[1] -= 1
        realCount = [0, 0]
        for n in nums:
            if n == items[0]:
                realCount[0] += 1
            elif n == items[1]:
                realCount[1] += 1
        return [items[i] for i in range(2) if realCount[i] > len(nums) // 3]
