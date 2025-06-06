from collections import deque

class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        n = len(status)
        q = deque()
        unopenedBox = [False] * n
        unusedKey = [False] * n
        opened = [False] * n
        for b in initialBoxes:
            if status[b]:
                q.append(b)
            else:
                unopenedBox[b] = True
        total = 0
        while len(q) != 0:
            b = q.pop()
            if opened[b]:
                continue
            opened[b] = True
            unopenedBox[b] = False
            total += candies[b]
            for nb in keys[b]:
                if unopenedBox[nb]:
                    q.append(nb)
                else:
                    unusedKey[nb] = True
            for nb in containedBoxes[b]:
                if status[nb] or unusedKey[nb]:
                    q.append(nb)
                else:
                    unopenedBox[nb] = True
        return total
