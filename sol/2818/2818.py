class Solution:
    M = 10 ** 9 + 7
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        score = [0] * n
        table = [2, 3, 5, 7]
        primeCandidate = 9
        for i, x in enumerate(nums):
            while table[-1] ** 2 < x:
                primeCandidate += 2
                if all(primeCandidate % prime != 0 for prime in table):
                    table.append(primeCandidate)
            count = 0
            for prime in table:
                if prime > x:
                    break
                if x % prime == 0:
                    count += 1
                    while x % prime == 0:
                        x //= prime
            if x != 1:
                count += 1
            score[i] = count
        lbdy = [-1] * n
        stack = [0]
        for i in range(1, n):
            while len(stack) != 0 and score[stack[-1]] < score[i]:
                stack.pop()
            if len(stack) != 0:
                lbdy[i] = stack[-1]
            stack.append(i)
        rbdy = [n] * n
        stack = [n - 1]
        for i in range(n - 2, -1, -1):
            while len(stack) != 0 and score[stack[-1]] <= score[i]:
                stack.pop()
            if len(stack) != 0:
                rbdy[i] = stack[-1]
            stack.append(i)
        res = 1
        for i in sorted(range(n), key=lambda idx: nums[idx], reverse=True):
            count = min(k, (i - lbdy[i]) * (rbdy[i] - i))
            k -= count
            res = (res * pow(nums[i], count, self.M)) % self.M
            if k == 0:
                break
        return res
