class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        if rows == 1 or len(encodedText) == 0:
            return encodedText
        n = len(encodedText)
        rowlen = n // rows
        return ''.join(encodedText[j::rowlen + 1] for j in range(rowlen)).rstrip()
