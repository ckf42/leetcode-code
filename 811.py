from collections import defaultdict

class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        visitCount = defaultdict(int)
        for rec in cpdomains:
            c, url = rec.split(maxsplit=1)
            count = int(c)
            domParts = url.split('.')
            l = len(domParts)
            d = domParts[-1]
            visitCount[d] += count
            for i in range(l - 2, -1, -1):
                d = domParts[i] + '.' + d
                visitCount[d] += count
        return [str(v) + " " + k for k, v in visitCount.items()]
