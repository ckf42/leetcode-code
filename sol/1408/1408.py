class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        joined = ' '.join(words)
        return [w for w in words if joined.count(w) > 1]
