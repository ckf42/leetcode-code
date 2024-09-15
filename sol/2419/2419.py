class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        maxele = nums[0]
        maxlen = 1
        currele = nums[0]
        currlen = 1
        for i in range(1, n):
            if nums[i] == currele:
                currlen += 1
            else:
                currele = nums[i]
                currlen = 1
            if currele > maxele or (currele == maxele and currlen > maxlen):
                maxele = currele
                maxlen = currlen
        return maxlen

