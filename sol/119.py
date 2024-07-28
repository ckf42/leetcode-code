class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [1] * (rowIndex + 1)
        for i in range(1, rowIndex + 1):
            res[i] = res[i - 1] * (rowIndex + 1 - i) // i
        return res
