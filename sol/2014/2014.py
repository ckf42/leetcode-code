class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        n = len(s)
        freq = dict()
        for c in s:
            freq[c] = freq.get(c, 0) + 1
        for c in tuple(freq.keys()):
            if freq[c] < k:
                del freq[c]
        cList = sorted(freq.keys(), reverse=True)
        def isAtLeastKRep(part):
            if part == '':
                return True
            subseq = ''.join(c for c in s if c in part)
            l = len(subseq)
            if l < len(part) * k:
                return False
            ptr = 0
            for c in (x for rep in range(k) for x in part):
                while ptr < l and subseq[ptr] != c:
                    ptr += 1
                if ptr == l:
                    return False
                ptr += 1
            return True
        res = ''
        def backtrack(currSub):
            nonlocal freq
            nonlocal res
            if len(currSub) * k > n:
                return
            if not isAtLeastKRep(currSub):
                return
            if len(currSub) > len(res) or (len(currSub) == len(res) and currSub > res):
                res = currSub
            for c in cList:
                if freq[c] == 0:
                    continue
                freq[c] -= 1
                newSub = currSub + c
                backtrack(newSub)
                freq[c] += 1
        backtrack('')
        return res
