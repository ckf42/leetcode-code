class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        d = dict()
        for i, v in enumerate(numbers):
            g = d.get(target - v, None)
            if g is not None:
                return (i + 1, g + 1) if i < g else (g + 1, i + 1)
            else:
                d[v] = i
