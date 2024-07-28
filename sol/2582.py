class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        k = n - 1
        time %= (2 * k)
        return (time if time <= k else 2 * k - time) + 1
