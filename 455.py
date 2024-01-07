class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        sptr = 0
        res = 0
        for gg in g:
            while sptr < len(s) and s[sptr] < gg:
                sptr += 1
            if sptr == len(s):
                break
            res += 1
            sptr += 1
        return res
