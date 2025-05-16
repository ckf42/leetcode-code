class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        M = 10 ** 9 + 7
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord('a')] += 1
        zptr = 25
        for _ in range(t):
            freq[(zptr + 1) % 26] += freq[zptr]
            freq[(zptr + 1) % 26] %= M
            zptr = (zptr + 25) % 26
        return sum(freq) % M
