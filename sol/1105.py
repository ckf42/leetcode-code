class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        memo = [1000001] * (n + 1)
        memo[0] = 0
        memo[1] = books[0][1]
        for i in range(1, n):
            w = 0
            h = 0
            for j in range(i, -1, -1):
                w += books[j][0]
                h = max(h, books[j][1])
                if w > shelfWidth:
                    break
                memo[i + 1] = min(memo[i + 1], memo[j] + h)
        return memo[n]
