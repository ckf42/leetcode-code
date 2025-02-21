class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        n = len(tiles)
        counter = dict()
        for x in tiles:
            counter[x] = counter.get(x, 0) + 1
        m = len(counter)
        def count(freq: list[int]) -> int:
            res = 1
            for i in range(m):
                if freq[i] == 0:
                    continue
                freq[i] -= 1
                res += count(freq)
                freq[i] += 1
            return res
        return count(list(counter.values())) - 1
