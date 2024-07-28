class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        n = len(nums)
        if n == 0:
            return None
        return TreeNode(
            nums[n // 2],
            self.sortedArrayToBST(nums[:n // 2]),
            self.sortedArrayToBST(nums[n // 2 + 1:])
        )
