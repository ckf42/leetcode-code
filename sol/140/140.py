class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        trie = dict()
        for i, w in enumerate(wordDict):
            ptr = trie
            for c in w:
                if c not in ptr:
                    ptr[c] = dict()
                ptr = ptr[c]
            ptr['='] = i
        n = len(s)
        memo = [list() for _ in range(n)]
        try:
            memo[n - 1].append([wordDict.index(s[-1])])
        except ValueError:
            pass
        for i in range(n - 2, -1, -1):
            ptr = trie
            for j in range(i, n - 1):
                if s[j] not in ptr:
                    break
                ptr = ptr[s[j]]
                if '=' in ptr:
                    for suff in memo[j + 1]:
                        memo[i].append(suff + [ptr['=']])
            else:
                if (idx := ptr.get(s[n - 1], dict()).get('=', None)) is not None:
                    memo[i].append([idx])
        return [' '.join(wordDict[i] for i in p[::-1]) for p in memo[0]]
