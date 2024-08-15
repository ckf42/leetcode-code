class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        memo = dict()
        for x in arr:
            memo[x] = memo.get(x - difference, 0) + 1
        return max(memo.values())

