from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        gps = defaultdict(list)
        for s in strs:
            gps[''.join(sorted(s))].append(s)
        return [v for v in gps.values()]
