class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        target = tickets[k]
        res = 0
        for i, t in enumerate(tickets):
            res += t if t < target else target - (i > k)
        return res
