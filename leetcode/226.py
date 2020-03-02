# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """

        def dfs(n):
            if n is None:
                return None
            tmp = dfs(n.left)
            n.left = dfs(n.right)
            n.right = tmp
            return n

        return dfs(root)
