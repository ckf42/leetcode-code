from collections import defaultdict

class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        n = len(nums)
        occur = defaultdict(list)
        for i, x in enumerate(nums):
            occur[x].append(i)
        badIdx = [list() for _ in range(n)]
        for i, x in enumerate(nums):
            badIdx[i].extend(j for j in occur[x - k] if j < i)
            badIdx[i].extend(j for j in occur[x + k] if j < i)
        msks = set()
        msks.add(0)
        for i in range(n):
            newMsks = set()
            for m in msks:
                if all((m & (1 << j)) == 0 for j in badIdx[i]):
                    newMsks.add(m | (1 << i))
            msks.update(newMsks)
        return len(msks) - 1
