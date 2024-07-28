class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        currWidth = 0
        lineCount = 0
        for c in s:
            newWidth = currWidth + widths[ord(c) - ord('a')]
            if newWidth > 100:
                lineCount += 1
                currWidth = newWidth - currWidth
            else:
                currWidth = newWidth
        return (lineCount + 1, currWidth)
