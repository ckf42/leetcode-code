class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        diffs = [0] * (n + 1)
        for start, end, isForward in shifts:
            change = isForward * 2 - 1
            diffs[start] += change
            diffs[end + 1] -= change
        diffs[0] %= 26
        for i in range(1, n + 1):
            diffs[i] = (diffs[i] + diffs[i - 1]) % 26
        orda = ord('a')
        return ''.join(chr((ord(c) - orda + diffs[i]) % 26 + orda) for i, c in enumerate(s))
