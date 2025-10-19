class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        res = []
        tag = ''
        for w in words:
            tagw = sorted(w)
            if tagw != tag:
                tag = tagw
                res.append(w)
        return res
