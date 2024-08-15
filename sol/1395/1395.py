class Solution:
    def numTeams(self, rating: List[int]) -> int:
        res = 0
        n = len(rating)
        for j in range(1, n - 1):
            l = sum(rating[i] < rating[j] for i in range(j))
            r = sum(rating[k] > rating[j] for k in range(j + 1, n))
            res += l * r + (j - l) * (n - j - 1 - r)
        return res
