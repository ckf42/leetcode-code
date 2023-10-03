from functools import cache

class Solution:
    @cache
    def letterCasePermutation(self, s: str) -> List[str]:
        if len(s) == 0:
            return [""]
        else:
            lst = list()
            if s[0].isalpha():
                for ss in self.letterCasePermutation(s[1:]):
                    lst.append(s[0].lower() + ss)
                    lst.append(s[0].upper() + ss)
            else:
                for ss in self.letterCasePermutation(s[1:]):
                    lst.append(s[0] + ss)
            return lst
