class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        res = [0] * n
        onLeft = 0
        onRight = 0
        for i in range(1, n):
            if boxes[i] == '1':
                onRight += 1
                res[0] += i
        for i in range(1, n):
            onLeft += (boxes[i - 1] == '1')
            res[i] = res[i - 1] + onLeft - onRight
            onRight -= (boxes[i] == '1')
        return res
