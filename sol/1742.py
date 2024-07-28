class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        boxes = [0] * 46
        def f(x):
            res = 0
            while x != 0:
                res += x % 10
                x //= 10
            return res
        for i in range(lowLimit, highLimit + 1):
            boxes[f(i)] += 1
        return max(boxes)
