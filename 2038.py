class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        asum = 0
        bsum = 0
        lastLetter = colors[0]
        lastIdx = 0
        for i, c in enumerate(colors[1:]):
            if c != lastLetter:
                if i - lastIdx >= 2:
                    if lastLetter == 'A':
                        asum += i - lastIdx - 1
                    else:
                        bsum += i - lastIdx - 1
                lastLetter = c
                lastIdx = i + 1
        if len(colors) - lastIdx >= 3:
            if lastLetter == 'A':
                asum += len(colors) - lastIdx - 2
            else:
                bsum += len(colors) - lastIdx - 2
        return asum > bsum

