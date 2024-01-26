class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def toMask(s):
            mask = 0
            for c in s:
                partialMask = (1 << (ord(c) - ord('a')))
                if partialMask & mask:
                    return None
                mask |= partialMask
            return mask

        n = len(arr)
        masks = tuple(toMask(s) for s in arr)

        def backtrack(currMask, startIdx, currLen):
            if startIdx == n:
                return currLen
            maxLen = backtrack(currMask, startIdx + 1, currLen)
            if masks[startIdx] is not None and (masks[startIdx] & currMask) == 0:
                maxLen = max(maxLen, 
                    backtrack(currMask | masks[startIdx], startIdx + 1, currLen + len(arr[startIdx])))
            return maxLen

        return backtrack(0, 0, 0)
        
