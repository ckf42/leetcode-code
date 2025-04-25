class Solution:
    def countLargestGroup(self, n: int) -> int:
        freq = [0] * 37
        for i in range(1, n + 1):
            total = 0
            while i != 0:
                i, r = divmod(i, 10)
                total += r
            freq[total] += 1
        return freq.count(max(freq))
