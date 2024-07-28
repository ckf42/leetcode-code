class Robot:
    dirstr = ['East', 'North', 'West', 'South']

    def __init__(self, width: int, height: int):
        self.w = width
        self.h = height
        self.d = 0
        self.x = 0
        self.y = 0
        self.count = 0
        self.circum = (width + height - 2) * 2
        self.moved = False

    def step(self, num: int) -> None:
        self.count += num
        self.moved |= (self.count != 0)
        if not self.moved:
            return
        self.count %= self.circum
        if self.count == 0:
            self.d = 3
            self.x = 0
            self.y = 0
        elif self.count < self.w:
            self.d = 0
            self.x = self.count
            self.y = 0
        elif self.count < self.w + self.h - 1:
            self.d = 1
            self.x = self.w - 1
            self.y = self.count - self.w + 1
        elif self.count < self.w * 2 + self.h - 2:
            self.d = 2
            self.x = self.w * 2 + self.h - 3 - self.count
            self.y = self.h - 1
        else:
            self.d = 3
            self.x = 0
            self.y = self.w * 2 + self.h * 2 - self.count - 4

    def getPos(self) -> List[int]:
        return [self.x, self.y]

    def getDir(self) -> str:
        return self.dirstr[self.d]

