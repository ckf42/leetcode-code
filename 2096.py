class Solution:
    stack = list()

    def getPath(self, root, target) -> bool:
        if root is None:
            return False
        if root.val == target:
            return True
        if self.getPath(root.left, target):
            self.stack.append('L')
            return True
        if self.getPath(root.right, target):
            self.stack.append('R')
            return True
        return False

    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        self.stack.clear()
        self.getPath(root, startValue)
        pathToStart = ''.join(self.stack[::-1])
        self.stack.clear()
        self.getPath(root, destValue)
        pathToEnd = ''.join(self.stack[::-1])
        ptr = 0
        minLen = min(len(pathToStart), len(pathToEnd))
        while ptr < minLen and pathToStart[ptr] == pathToEnd[ptr]:
            ptr += 1
        return 'U' * (len(pathToStart) - ptr) + pathToEnd[ptr:]
