from collections import deque

class Solution:
    GOALCONFIG = (1, 2, 3, 4, 5, 0)
    SWAPLOC = (
        (1, 3),
        (0, 2, 4),
        (1, 5),
        (4, 0),
        (3, 5, 1),
        (4, 2)
    )

    def slidingPuzzle(self, board: List[List[int]]) -> int:
        initConfig = tuple(x for r in board for x in r)
        q = deque([(0, initConfig)])
        visited = set()
        while len(q) != 0:
            mvs, config = q.popleft()
            if config == self.GOALCONFIG:
                return mvs
            if config in visited:
                continue
            visited.add(config)
            mvs += 1
            idx = config.index(0)
            mutConfig = list(config)
            for l in self.SWAPLOC[idx]:
                mutConfig[l], mutConfig[idx] = mutConfig[idx], mutConfig[l]
                q.append((mvs, tuple(mutConfig)))
                mutConfig[l], mutConfig[idx] = mutConfig[idx], mutConfig[l]
        return -1
