import heapq as hq

class SeatManager:
    def __init__(self, n: int):
        self.h = list(range(1, n + 1))

    def reserve(self) -> int:
        return hq.heappop(self.h)

    def unreserve(self, seatNumber: int) -> None:
        hq.heappush(self.h, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
