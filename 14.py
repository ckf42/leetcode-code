class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]
        ptr = len(strs[0])
        for i in range(1, len(strs)):
            ptr = min(ptr, len(strs[i]))
            for j in range(ptr):
                if strs[0][j] != strs[i][j]:
                    ptr = j
                    break
        return strs[0][:ptr]
