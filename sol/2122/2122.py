from collections import defaultdict

class Solution:
    def recoverArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nums.sort()
        indices = defaultdict(list)
        for i, x in enumerate(nums):
            indices[x].append(i)
        for i in range(1, n):
            if nums[i] == nums[0] or ((nums[i] - nums[0]) & 1) != 0:
                continue
            k = (nums[i] - nums[0]) >> 1
            paired = [False] * n
            paired[0] = paired[i] = True
            res = [nums[0] + k]
            for j in range(1, n):
                if paired[j]:
                    continue
                for idx in indices[nums[j] + 2 * k]:
                    if not paired[idx]:
                        res.append(nums[j] + k)
                        paired[j] = paired[idx] = True
                        break
                else:
                    break
            else:
                return res
        return []
