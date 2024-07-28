class Solution:
    offset = 50000
    def sortArray(self, nums: List[int]) -> List[int]:
        msk = 0
        for _ in range(5):
            buckets = [list() for _ in range(16)]
            for x in nums:
                buckets[((x + self.offset) >> (msk << 2)) & 15].append(x)
            nums = [x for b in buckets for x in b]
            msk += 1
        return nums
