class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        occurred = [False] * 26
        count = 0
        for c in sentence:
            if not occurred[ord(c) - ord('a')]:
                count += 1
            occurred[ord(c) - ord('a')] = True
        return count == 26
