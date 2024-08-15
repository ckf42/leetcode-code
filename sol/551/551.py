class Solution:
    def checkRecord(self, s: str) -> bool:
        consecLCount = 0
        prevIsL = False
        aCount = 0
        for c in s:
            if c == 'A':
                aCount += 1
                if aCount == 2:
                    return False
                prevIsL = False
            elif c == 'L':
                if prevIsL:
                    consecLCount += 1
                    if consecLCount == 3:
                        return False
                else:
                    prevIsL = True
                    consecLCount = 1
            else:
                prevIsL = False
        return True
