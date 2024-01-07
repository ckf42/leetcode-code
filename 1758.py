class Solution:
    def minOperations(self, s: str) -> int:
        count = 0
        for i, c in enumerate(s):
            if c == ('1' if i & 1 else '0'):
                count += 1
        return min(count, len(s) - count)
