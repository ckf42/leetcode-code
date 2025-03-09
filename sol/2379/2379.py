class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        n = len(blocks)
        res = 0
        for c in blocks[:k]:
            res += c == 'W'
        count = res
        for i in range(k, n):
            count += (blocks[i] == 'W') - (blocks[i - k] == 'W')
            res = min(res, count)
        return res
