class MyQueue:

    def __init__(self):
        self.tail: list[int] = list()
        self.head: list[int] = list()

    def push(self, x: int) -> None:
        self.tail.append(x)

    def pop(self) -> int:
        self.peek()
        return self.head.pop()

    def peek(self) -> int:
        if len(self.head) == 0:
            while len(self.tail) != 0:
                self.head.append(self.tail.pop())
        return self.head[-1]

    def empty(self) -> bool:
        return len(self.head) == 0 and len(self.tail) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
