from collections import Counter

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        freq = sorted(Counter(arr).values())
        ptr = 0
        m = len(freq)
        while k > 0 and ptr < m and k >= freq[ptr]:
            k -= freq[ptr]
            ptr += 1
        return m - ptr
