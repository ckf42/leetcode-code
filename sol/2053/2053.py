class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        d = dict()
        for s in arr:
            d[s] = d.get(s, 0) + 1
        if len(d) < k:
            return ""
        for s, c in d.items():
            if c == 1:
                k -= 1
            if k == 0:
                return s
        return ""
