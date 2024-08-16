class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        maxvals = [None, None]
        minvals = [None, None]
        for i, arr in enumerate(arrays):
            if minvals[0] is None or arrays[minvals[0]][0] > arr[0]:
                minvals[1] = minvals[0]
                minvals[0] = i
            elif minvals[1] is None or arrays[minvals[1]][0] > arr[0]:
                minvals[1] = i
            if maxvals[0] is None or arrays[maxvals[0]][-1] < arr[-1]:
                maxvals[1] = maxvals[0]
                maxvals[0] = i
            elif maxvals[1] is None or arrays[maxvals[1]][-1] < arr[-1]:
                maxvals[1] = i
        if maxvals[0] != minvals[0]:
            return arrays[maxvals[0]][-1] - arrays[minvals[0]][0]
        else:
            return max(
                arrays[maxvals[0]][-1] - arrays[minvals[1]][0],
                arrays[maxvals[1]][-1] - arrays[minvals[0]][0]
            )
