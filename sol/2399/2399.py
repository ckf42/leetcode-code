class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        indices = [-1] * 26
        oa = ord('a')
        for i, c in enumerate(s):
            o = ord(c) - oa
            if indices[o] == -1:
                indices[o] = i
            elif i - indices[o] != distance[o] + 1:
                return False
        return True
