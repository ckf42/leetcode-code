from collections import defaultdict

class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res = 0
        count = defaultdict(int)
        count[nums[-1]] = 1
        distinct = 1
        emin = 0
        emax = 0
        for s in range(-1, n):  # now drop nums[s]
            count[nums[s]] -= 1
            if count[nums[s]] == 0:
                distinct -= 1
                while emin < n and distinct != k:
                    count[nums[emin]] += 1
                    if count[nums[emin]] == 1:
                        distinct += 1
                    emin += 1
                emax = max(emax, emin)
                while emax < n and count[nums[emax]] != 0:
                    emax += 1
            if distinct != k:
                break
            res += emax - emin + 1
        return res
