class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * (len(s) + 1)
        dp[-1] = True
        for i in range(len(s) - 1, -1, -1):
            for w in wordDict:
                if i + len(w) <= len(s) and s[i:i + len(w)] == w and dp[i + len(w)]:
                    dp[i] = True
                    break
        return dp[0]

# class Solution:
#     def wordBreak(self, s: str, wordDict: List[str]) -> bool:
#         trie = dict()
#         for w in wordDict:
#             ptr = trie
#             for c in w:
#                 if c not in ptr:
#                     ptr[c] = dict()
#                 ptr = ptr[c]
#             ptr[''] = True
#         dp = [None] * len(s)
#         for i in range(len(s) - 1, -1, -1):
#             ptr = trie
#             for j in range(i, len(s)):
#                 if '' in ptr and dp[j] is True:
#                     dp[i] = True
#                     break
#                 elif s[j] not in ptr:
#                     dp[i] = False
#                     break
#                 else:
#                     ptr = ptr[s[j]]
#             if dp[i] is None:
#                 dp[i] = '' in ptr
#         return dp[0]
