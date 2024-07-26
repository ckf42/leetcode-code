class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        freq = dict()
        for x in nums:
            freq[x] = freq.get(x, 0) + 1
        nums.sort(reverse=True)
        nums.sort(key=lambda x: freq[x])
        return nums
