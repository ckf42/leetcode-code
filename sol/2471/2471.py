from collections import deque

class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        count = 0
        q = deque([root])
        while (n := len(q)) != 0:
            nextIdx = sorted(range(n), key=lambda idx: q[idx].val)
            visited = [False] * n
            for i in range(n):
                if visited[i]:
                    continue
                ptr = i
                loopLen = -1
                while not visited[ptr]:
                    visited[ptr] = True
                    ptr = nextIdx[ptr]
                    loopLen += 1
                count += loopLen
            for _ in range(n):
                node = q.popleft()
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
        return count
