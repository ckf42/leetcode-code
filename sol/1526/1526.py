class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        res = 0
        curr = 0
        for x in target:
            if x < curr:
                res += curr - x
            curr = x
        return res + curr
