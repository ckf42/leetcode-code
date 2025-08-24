class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        startWithOne = nums[0] == 1
        seq = []
        prev = nums[0]
        count = 1
        res = 0
        for x in nums[1:]:
            if x != prev:
                seq.append(count)
                if prev == 1:
                    res = max(res, count)
                count = 0
                prev = x
            count += 1
        seq.append(count)
        if prev == 1:
            res = max(res, count)
        if len(seq) == 1:
            return n - 1 if startWithOne else 0
        prevSeg = 0
        l = len(seq)
        for i in range(1 if startWithOne else 2, l, 2):
            if seq[i] == 1 and i < l - 1:
                res = max(res, seq[i - 1] + seq[i + 1])
        return res
