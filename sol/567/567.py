class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l = len(s1)
        if l > len(s2):
            return False
        freq = [0] * 26
        for i in range(l):
            freq[ord(s1[i]) - ord('a')] -= 1
            freq[ord(s2[i]) - ord('a')] += 1
        zCount = sum(1 for i in range(26) if freq[i] == 0)
        if zCount == 26:
            return True
        for i in range(l, len(s2)):
            j = ord(s2[i]) - ord('a')
            freq[j] += 1
            if freq[j] == 0:
                zCount += 1
            elif freq[j] == 1:
                zCount -= 1
            j = ord(s2[i - l]) - ord('a')
            freq[j] -= 1
            if freq[j] == 0:
                zCount += 1
            elif freq[j] == -1:
                zCount -= 1
            if zCount == 26:
                return True
        return False

