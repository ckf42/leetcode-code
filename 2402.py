import heapq as hq

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        hitCount = [0] * n
        vacRooms = [i for i in range(n)]
        hq.heapify(vacRooms)
        roomInUse = []
        for meet in meetings:
            while len(roomInUse) != 0 and roomInUse[0][0] <= meet[0]:
                hq.heappush(vacRooms, hq.heappop(roomInUse)[1])
            roomId = -1
            if len(vacRooms) != 0:
                roomId = hq.heappop(vacRooms)
            else:
                availTime, roomId = hq.heappop(roomInUse)
                meet[1] += availTime - meet[0]
            hitCount[roomId] += 1
            hq.heappush(roomInUse, (meet[1], roomId))
        return hitCount.index(max(hitCount))
