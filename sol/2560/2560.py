class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        n = len(nums)
        indices = sorted(range(n), key=lambda i: nums[i])
        s = k - 1
        e = n
        while s < e:
            m = (s + e) // 2
            cap = nums[indices[m]]
            total = 0
            taken = False
            for x in nums:
                if not taken and x <= cap:
                    taken = True
                    total += 1
                else:
                    taken = False
            if total >= k:
                e = m
            else:
                s = m + 1
        return nums[indices[s]]
