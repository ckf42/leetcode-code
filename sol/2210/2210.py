class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        uq = [nums[0]]
        for x in nums[1:]:
            if x != uq[-1]:
                uq.append(x)
        n = len(uq)
        return sum(
            1
            for i in range(1, n - 1)
            if (uq[i] > uq[i - 1] and uq[i] > uq[i + 1]) \
                    or (uq[i] < uq[i - 1] and uq[i] < uq[i + 1])
        )
