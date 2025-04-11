class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        seen = set()
        count = 0
        for x in nums[::-1]:
            if x in seen:
                break
            seen.add(x)
            count += 1
        return (n - count + 2) // 3
