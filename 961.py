class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        appeared = set()
        for n in nums:
            if n not in appeared:
                appeared.add(n)
            else:
                return n
