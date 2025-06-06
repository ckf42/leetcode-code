class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word
        n = len(word)
        l = n - numFriends + 1
        return max(
            max(word[i:i + l] for i in range(n - l + 1)),
            max((word[-i:] for i in range(1, l)), default='')
        )
