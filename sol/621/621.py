from collections import Counter

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counts = tuple(x[1] for x in Counter(tasks).most_common())
        chunk = counts[0] - 1
        idleCount = chunk * n
        for idx in range(1, len(counts)):
            idleCount -= min(chunk, counts[idx])
            if idleCount <= 0:
                break
        return len(tasks) + max(0, idleCount)
