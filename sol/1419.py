class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        freq = [0] * 5
        res = 0
        count = 0
        indices = {c: i for i, c in enumerate('roak')}
        for c in croakOfFrogs:
            if c == 'c':
                freq[0] += 1
                count += 1
                res = max(res, count)
            else:
                idx = indices[c]
                if freq[idx] == 0:
                    return -1
                freq[idx] -= 1
                if c != 'k':
                    freq[idx + 1] += 1
                else:
                    count -= 1
        return res if all(x == 0 for x in freq) else -1
