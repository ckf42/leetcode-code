class CustomStack:
    def __init__(self, maxSize: int):
        self.maxSize: int = maxSize
        self.diff: list[int] = [0] * maxSize
        self.ptr : int = 0
        self.stackTop: int = -1

    def push(self, x: int) -> None:
        if self.ptr == self.maxSize:
            return
        self.diff[self.ptr] = self.stackTop - x
        self.ptr += 1
        self.stackTop = x

    def pop(self) -> int:
        if self.ptr == 0:
            return -1
        buff = self.stackTop
        self.ptr -= 1
        self.stackTop += self.diff[self.ptr]
        return buff

    def increment(self, k: int, val: int) -> None:
        if k >= self.ptr:
            self.stackTop += val
        else:
            self.diff[k] += val

