class Solution:
    valDict: dict[str, int] = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    def romanToInt(self, s: str) -> int:
        totalVal = 0
        lastVal = 1001
        for c in s:
            val = self.valDict[c]
            if val > lastVal:
                totalVal -= 2 * lastVal
            totalVal += val
            lastVal = val
        return totalVal
