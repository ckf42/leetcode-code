class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False
        freq = [0] * 26
        total = len(ransomNote)
        for c in ransomNote:
            freq[ord(c) - ord('a')] += 1
        for c in magazine:
            idx = ord(c) - ord('a')
            if freq[idx] > 0:
                freq[idx] -= 1
                total -= 1
            if total == 0:
                return True
        return False
