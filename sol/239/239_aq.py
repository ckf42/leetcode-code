class Solution:
    class AnnotatedQueue:
        def __init__(self):
            self.front: list[tuple[int, int]] = []
            self.back: list[tuple[int, int]] = []

        def append(self, e: int):
            if len(self.back) == 0:
                self.back.append((e, e))
            else:
                self.back.append((e, max(e, self.back[-1][1])))

        def getMax(self) -> int:
            mf = -float('inf')
            mb = -float('inf')
            if len(self.front) != 0:
                mf = self.front[-1][1]
            if len(self.back) != 0:
                mb = self.back[-1][1]
            return max(mf, mb)

        def pop(self) -> int | None:
            if len(self.front) == 0 and len(self.back) == 0:
                return None
            if len(self.front) == 0:
                e = self.back.pop()[0]
                self.front.append((e, e))
                while len(self.back) != 0:
                    e = self.back.pop()[0]
                    self.front.append((e, max(e, self.front[-1][1])))
            return self.front.pop()[0]

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        res = [0] * (n - k + 1)
        q = self.AnnotatedQueue()
        for i in range(k):
            q.append(nums[i])
        res[0] = q.getMax()
        for i in range(k, n):
            q.append(nums[i])
            q.pop()
            res[i - k + 1] = q.getMax()
        return res

