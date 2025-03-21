class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        counter = dict()
        for x in nums:
            counter[x] = counter.get(x, 0) + 1
        return all((v & 1) == 0 for v in counter.values())
