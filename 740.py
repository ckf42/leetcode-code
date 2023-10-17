from collections import Counter

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        counts = Counter(nums)
        keys = sorted(counts.keys())
        if len(keys) == 1:
            return counts[keys[0]] * keys[0]
        prev = counts[keys[0]] * keys[0]
        val = counts[keys[1]] * keys[1]
        if keys[1] == keys[0] + 1:
            val = max(prev, val)
        else:
            val += prev
        for i in range(2, len(keys)):
            temp = counts[keys[i]] * keys[i]
            if keys[i] == keys[i - 1] + 1:
                temp = max(temp + prev, val)
            else:
                temp += val
            prev, val = val, temp
        return val
