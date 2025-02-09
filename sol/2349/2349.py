import heapq as hq
from collections import defaultdict

class NumberContainers:
    def __init__(self):
        self.indexDict: dict[int, int] = dict()  # index -> number
        self.indexHeap: defaultdict[int, list[int]] = defaultdict(list)  # number -> heap[index]

    def change(self, index: int, number: int) -> None:
        self.indexDict[index] = number
        hq.heappush(self.indexHeap[number], index)

    def find(self, number: int) -> int:
        while len(self.indexHeap[number]) != 0:
            idx = self.indexHeap[number][0]
            if self.indexDict[idx] == number:
                return idx
            hq.heappop(self.indexHeap[number])
        return -1

