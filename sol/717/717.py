class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n = len(bits)
        ptr = 0
        lastIsSingle = False
        while ptr < n:
            if bits[ptr] == 0:
                lastIsSingle = True
                ptr += 1
            else:
                lastIsSingle = False
                ptr += 2
        return lastIsSingle
