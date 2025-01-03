class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = frozenset('aeiou')
        n = len(words)
        vowelStrCount = [0] * (n + 1)  # [0:i)
        for i in range(n):
            vowelStrCount[i + 1] = vowelStrCount[i] + int((words[i][0] in vowels) and (words[i][-1] in vowels))
        return [vowelStrCount[b + 1] - vowelStrCount[a] for a, b in queries]
