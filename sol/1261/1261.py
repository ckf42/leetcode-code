class FindElements:
    def __init__(self, root: Optional[TreeNode]):
        self.root = root

    def find(self, target: int) -> bool:
        target += 1
        mask = 1
        while mask <= target:
            mask <<= 1
        mask >>= 2
        ptr = self.root
        while ptr is not None and mask != 0:
            if target & mask:
                ptr = ptr.right
            else:
                ptr = ptr.left
            mask >>= 1
        return ptr is not None

