class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        inCounter = [0] * n
        for i, node in enumerate(leftChild):
            if node == -1:
                continue
            if i == node:
                return False
            inCounter[node] += 1
        for i, node in enumerate(rightChild):
            if node == -1:
                continue
            if i == node:
                return False
            inCounter[node] += 1
        print(inCounter)
        idx = -1
        try:
            idx = inCounter.index(0)
        except ValueError:
            return False
        try:
            inCounter.index(0, idx + 1)
            return False
        except ValueError:
            pass
        if any(v >= 2 for v in inCounter):
            return False
        visitStack = [idx]
        visited = set()
        while len(visitStack) != 0:
            node = visitStack.pop()
            if node in visited:
                return False
            visited.add(node)
            if leftChild[node] != -1:
                visitStack.append(leftChild[node])
            if rightChild[node] != -1:
                visitStack.append(rightChild[node])
        return len(visited) == n
            
        

