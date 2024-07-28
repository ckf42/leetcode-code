class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        lLen = len(str(low))
        hLen = len(str(high))
        res = list()
        return [
            val
            for l in range(lLen, hLen + 1)
            for d in range(1, 9 - l + 2)
            if low <= (val := int(''.join(str(i) for i in range(d, l + d)))) <= high
        ]
