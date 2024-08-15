class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        prevIdx = 0
        buff = []
        for idx in spaces:
            buff.append(s[prevIdx:idx])
            prevIdx = idx
        buff.append(s[prevIdx:])
        return " ".join(buff)
