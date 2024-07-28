class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        targetSt = tuple(ord(d) - 48 for d in target)
        visited = set(tuple(ord(d) - 48 for d in st) for st in deadends)
        states = set(((0,) * 4,))
        counter = 0
        while len(states) != 0:
            newStates = set()
            for st in states:
                if st in visited:
                    continue
                if st == targetSt:
                    return counter
                for i in range(4):
                    newSt = list(st)
                    newSt[i] = (st[i] + 1) % 10
                    newStates.add(tuple(newSt))
                    newSt[i] = (st[i] - 1) % 10
                    newStates.add(tuple(newSt))
            visited.update(states)
            states = newStates
            counter += 1
        return -1
