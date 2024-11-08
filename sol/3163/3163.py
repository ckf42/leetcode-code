class Solution:
    def compressedString(self, word: str) -> str:
        res = ''
        lastChar = ''
        count = 0
        for c in word:
            if c == lastChar:
                count += 1
            else:
                while count > 9:
                    res += f'9{lastChar}'
                    count -= 9
                if count != 0:
                    res += f'{count}{lastChar}'
                lastChar = c
                count = 1
        while count > 9:
            res += f'9{lastChar}'
            count -= 9
        if count != 0:
            res += f'{count}{lastChar}'
        return res
