class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        m = 10 ** 9 + 7
        memo = [0] * forget
        memo[0] = 1
        idx = 0
        total = 0
        for _ in range(n - 1):
            idx = (idx + forget - 1) % forget
            total = (total + memo[(idx + delay) % forget] - memo[idx]) % m
            memo[idx] = total
        return sum(memo) % m
