from collections import Counter

class Solution:
    def maxFreqSum(self, s: str) -> int:
        c = Counter(s)
        maxVowel = 0
        maxConso = 0
        for ch, freq in c.items():
            if ch in 'aeiou':
                maxVowel = max(maxVowel, freq)
            else:
                maxConso = max(maxConso, freq)
        return maxVowel + maxConso
