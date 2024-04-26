class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        memo = [0] * 128
        for i, c in enumerate(s):
            idx = ord(c)
            memo[idx] = max(memo[idx - k:idx + k + 1]) + 1
        return max(memo[ord('a'):ord('z') + 1])
