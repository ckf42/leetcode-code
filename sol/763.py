class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        n = len(s)
        lastOccur = dict()
        for i, c in enumerate(s):
            lastOccur[c] = i
        res = []
        ptr = 0
        while ptr < n:
            i = ptr
            e = lastOccur[s[ptr]]
            while ptr < e:
                ptr += 1
                e = max(e, lastOccur[s[ptr]])
            ptr += 1
            res.append(ptr - i)
        return res
