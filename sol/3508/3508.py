import bisect
from collections import deque

class Router:

    def __init__(self, memoryLimit: int):
        self.lim = memoryLimit
        self.porder = deque()
        self.packets = dict()
        self.seen = set()

    def _remove(self, s, d, t):
        self.seen.remove((s, d, t))
        # assert self.packets[d][0] == t
        self.packets[d].popleft()

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        p = (source, destination, timestamp)
        if p in self.seen:
            return False
        if len(self.porder) == self.lim:
            s, d, t = self.porder.popleft()
            self._remove(s, d, t)
        self.seen.add(p)
        self.porder.append(p)
        if destination not in self.packets:
            self.packets[destination] = deque()
        self.packets[destination].append(timestamp)
        return True

    def forwardPacket(self) -> List[int]:
        if len(self.porder) == 0:
            return []
        s, d, t = self.porder.popleft()
        self._remove(s, d, t)
        return [s, d, t]

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        if destination not in self.packets:
            return 0
        q = self.packets[destination]
        a = bisect.bisect_left(q, startTime)
        b = bisect.bisect(q, endTime)
        return b - a

