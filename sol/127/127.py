from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList = set(wordList)
        if endWord not in wordList:
            return 0
        dep = 2
        q = deque((beginWord,))
        while (s := len(q)) != 0:
            for _ in range(s):
                w = list(q.popleft())
                for i in range(len(w)):
                    c = w[i]
                    for j in range(26):
                        w[i] = chr(ord('a') + j)
                        ww = ''.join(w)
                        if ww == endWord:
                            return dep
                        if ww in wordList:
                            wordList.remove(ww)
                            q.append(ww)
                    w[i] = c
            dep += 1
        return 0
