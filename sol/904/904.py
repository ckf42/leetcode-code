class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        n = len(fruits)
        count = [0] * n
        typeCount = 0
        res = 0
        l = 0
        for r in range(n):
            x = fruits[r]
            count[x] += 1
            if count[x] == 1:
                typeCount += 1
            while typeCount > 2:
                x = fruits[l]
                count[x] -= 1
                if count[x] == 0:
                    typeCount -= 1
                l += 1
            res = max(res, r - l + 1)
        return res
