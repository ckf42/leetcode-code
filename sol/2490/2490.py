class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        w = sentence.split()
        for i in range(len(w)):
            if w[i - 1][-1] != w[i][0]:
                return False
        return True
