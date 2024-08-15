class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        checked = [False] * len(nums)
        for (s, e) in zip(l, r):
            if e - s <= 1:
                yield True
                continue
            maxi, mini = max(nums[s:e + 1]), min(nums[s:e + 1])
            if maxi == mini:
                yield True
                continue
            diff, r = divmod(maxi - mini, e - s)
            if r != 0:
                yield False
                continue
            checked[:e - s + 1] = [False] * (e - s + 1)
            yielded = False
            for v in nums[s:e + 1]:
                q, r = divmod(v - mini, diff)
                if r != 0:
                    yield False
                    yielded = True
                    break
                checked[q] = True
            if not yielded:
                yield all(checked[:e - s + 1])

                    
