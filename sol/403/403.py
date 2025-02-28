class Solution:
    def canCross(self, stones: List[int]) -> bool:
        if stones[1] != 1:
            return False
        n = len(stones)
        if n == 2:
            return True
        indices = {x: i for i, x in enumerate(stones)}
        visited = set()
        buff = [(0, 1)]
        while len(buff) != 0:
            i, j = buff.pop()
            if (i, j) in visited:
                continue
            visited.add((i, j))
            base = stones[j] * 2 - stones[i]
            for delta in (-1, 0, 1):
                k = indices.get(base + delta, -1)
                if k == n - 1:
                    return True
                elif k > j:
                    buff.append((j, k))
        return False
