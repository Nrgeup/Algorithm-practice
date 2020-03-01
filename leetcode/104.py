# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        max_d = [0]

        def dfs(node, d):
            if max_d[0] < d:
                max_d[0] = d
            if node.left is not None:
                dfs(node.left, d + 1)
            if node.right is not None:
                dfs(node.right, d + 1)
            return

        if root is not None:
            dfs(root, 1)

        return max_d[0]
