class MinStack:
    def __init__(self):
        self.data: list[int] = []
        self.order: list[int] = []

    def push(self, val: int) -> None:
        self.data.append(val)
        if len(self.order) == 0 or self.order[-1] >= val:
            self.order.append(val)
        else:
            self.order.append(self.order[-1])

    def pop(self) -> None:
        self.order.pop()
        return self.data.pop()

    def top(self) -> int:
        return self.data[-1]

    def getMin(self) -> int:
        return self.order[-1]

