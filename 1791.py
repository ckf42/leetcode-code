class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        e1, e2 = edges[:2]
        if e1[0] in e2:
            return e1[0]
        else:
            return e1[1]
