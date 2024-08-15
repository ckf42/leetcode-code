class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        worker.sort()
        jobs = sorted(zip(difficulty, profit))
        ptr = 0
        n = len(jobs)
        res = 0
        maxProfit = 0
        for w in worker:
            while ptr < n and jobs[ptr][0] <= w:
                maxProfit = max(maxProfit, jobs[ptr][1])
                ptr += 1
            res += maxProfit
        return res
