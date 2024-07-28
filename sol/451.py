from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        return ''.join(c * f for (c, f) in Counter(s).most_common())
