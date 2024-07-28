class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        fidStack = list()
        exclTime = [0] * n
        for line in logs:
            fid, event, timestamp = line.split(':')
            fid = int(fid)
            timestamp = int(timestamp)
            if event == 'end':
                threadTime = timestamp - fidStack[-1][1] + 1
                exclTime[fid] += threadTime
                fidStack.pop()
                if len(fidStack) != 0:
                    exclTime[fidStack[-1][0]] -= threadTime
            else:
                fidStack.append((fid, timestamp))
        return exclTime
