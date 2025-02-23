class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        pres = 0
        posts = 0
        def recover():
            nonlocal pres, posts
            v = preorder[pres]
            pres += 1
            newNode = TreeNode(v)
            if v != postorder[posts]:
                newNode.left = recover()
            if v != postorder[posts]:
                newNode.right = recover()
            posts += 1
            return newNode
        return recover()
