import heapq as hq

class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        n = len(times)
        idx = list(range(n))
        idx.sort(key=lambda i: times[i][0])
        nextChair = 0
        peopleHeap = []
        chairHeap = []
        for i in idx:
            chair = -1
            while len(peopleHeap) != 0 and peopleHeap[0][0] <= times[i][0]:
                _, emptyChair = hq.heappop(peopleHeap)
                hq.heappush(chairHeap, emptyChair)
            if len(chairHeap) == 0:
                chair = nextChair
                nextChair += 1
            else:
                chair = hq.heappop(chairHeap)
            hq.heappush(peopleHeap, (times[i][1], chair))
            if i == targetFriend:
                return chair
        return -1
