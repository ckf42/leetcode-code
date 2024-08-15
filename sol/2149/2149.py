class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos, neg = [], []
        for x in nums:
            if x > 0:
                pos.append(x)
            else:
                neg.append(x)
        for i in range(len(nums)):
            nums[i] = (neg if i & 1 else pos)[i >> 1]
        return nums
