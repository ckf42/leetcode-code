import heapq as hq

class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.taskList = dict()
        self.pq = list()
        self.removed = set()
        for u, t, p in tasks:
            self.taskList[t] = (u, p)
            self.pq.append((-p, -t))
        hq.heapify(self.pq)

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.taskList[taskId] = (userId, priority)
        hq.heappush(self.pq, (-priority, -taskId))
        self.removed.discard(taskId)

    def edit(self, taskId: int, newPriority: int) -> None:
        u, p = self.taskList[taskId]
        if newPriority == p:
            return
        self.taskList[taskId] = (u, newPriority)
        hq.heappush(self.pq, (-newPriority, -taskId))

    def rmv(self, taskId: int) -> None:
        del self.taskList[taskId]
        self.removed.add(taskId)

    def execTop(self) -> int:
        while len(self.pq) != 0:
            p, t = hq.heappop(self.pq)
            if -t in self.removed:
                continue
            u, p_correct = self.taskList[-t]
            if p_correct != -p:
                continue
            self.removed.add(-t)
            return u
        return -1

