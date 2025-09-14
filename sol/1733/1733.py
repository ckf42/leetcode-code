class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        langSets = list(map(set, languages))
        m = len(languages)
        userCount = [0] * (n + 1)
        counted = [False] * (m + 1)
        total = 0
        for a, b in friendships:
            if not langSets[a - 1].isdisjoint(langSets[b - 1]):
                continue
            for x in (a, b):
                if not counted[x]:
                    counted[x] = True
                    total += 1
                    for lang in langSets[x - 1]:
                        userCount[lang] += 1
        return total - max(userCount)

