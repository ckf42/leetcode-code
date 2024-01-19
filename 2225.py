class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        noLose = set()
        oneLose = set()
        moreLose = set()
        for w, l in matches:
            if w not in oneLose and w not in moreLose:
                noLose.add(w)
            if l in noLose:
                noLose.remove(l)
                oneLose.add(l)
            elif l in oneLose:
                oneLose.remove(l)
                moreLose.add(l)
            elif l not in moreLose:
                oneLose.add(l)
        return [sorted(noLose), sorted(oneLose)]

