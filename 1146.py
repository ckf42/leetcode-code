from collections import defaultdict, namedtuple
from bisect import bisect

class SnapshotArray:
    Edit = namedtuple('Edit', ('id', 'val'))
    def __init__(self, length: int):
        # stores idx :> [(eff_id, val), ...]
        self.history = defaultdict(list)
        # snap_id to return on next snap() call
        self.effectiveID: int = 0

    def set(self, index: int, val: int) -> None:
        newEdit = SnapshotArray.Edit(self.effectiveID, val)
        if len(self.history[index]) == 0:
            self.history[index].append(newEdit)
        else:
            lastEdit = self.history[index][-1]
            if lastEdit.val != val:
                if lastEdit.id != self.effectiveID:
                    self.history[index].append(newEdit)
                else:
                    self.history[index][-1] = newEdit

    def snap(self) -> int:
        self.effectiveID = self.effectiveID + 1
        return self.effectiveID - 1

    def get(self, index: int, snap_id: int) -> int:
        if len(self.history[index]) == 0:
            return 0
        effId = bisect(self.history[index], snap_id, key=lambda e: e.id)
        return 0 if effId == 0 else self.history[index][effId - 1].val
