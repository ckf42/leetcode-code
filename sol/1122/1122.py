class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        keymap = dict()
        for x in arr1:
            keymap[x] = 1000 + x
        for i, x in enumerate(arr2):
            keymap[x] = i
        arr1.sort(key=lambda x: keymap[x])
        return arr1
