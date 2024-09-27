from sortedcontainers import SortedDict

class MyCalendar:
    def __init__(self):
        self.data = SortedDict()

    def book(self, start: int, end: int) -> bool:
        idx = self.data.bisect_right(start)
        if idx != len(self.data) and self.data.peekitem(idx)[1] < end:
            return False
        self.data[end] = start
        return True

