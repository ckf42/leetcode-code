class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        freq = [0] * 10
        for d in digits:
            freq[d] += 1
        res = []
        for d1 in range(1, 10):
            if freq[d1] == 0:
                continue
            freq[d1] -= 1
            for d2 in range(10):
                if freq[d2] == 0:
                    continue
                freq[d2] -= 1
                for d3 in range(0, 10, 2):
                    if freq[d3] == 0:
                        continue
                    res.append(100 * d1 + 10 * d2 + d3)
                freq[d2] += 1
            freq[d1] += 1
        return res
