class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total & 1:
            return False
        seen = set([0])
        for x in nums:
            newSeen = [val + x for val in seen]
            seen.update(newSeen)
        return (total // 2) in seen
