class Solution:
    def maximumTime(self, time: str) -> str:
        letters = list(time)
        if letters[0] == '?':
            letters[0] = '2' if letters[1] == '?' or int(letters[1]) < 4 else '1'
        if letters[1] == '?':
            letters[1] = '3' if letters[0] == '2' else '9'
        if letters[3] == '?':
            letters[3] = '5'
        if letters[4] == '?':
            letters[4] = '9'
        return ''.join(letters)
