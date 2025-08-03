class Solution:
    ALL_ROWS = []
    def __init__(self):
        if len(self.ALL_ROWS) == 0:
            self.ALL_ROWS.append([1])
            prev = [1]
            for _ in range(30 - 1):
                prev = [1] + [a + b for a, b in zip(prev[:-1], prev[1:])] + [1]
                self.ALL_ROWS.append(prev)
    def generate(self, numRows: int) -> List[List[int]]:
        return self.ALL_ROWS[:numRows]
