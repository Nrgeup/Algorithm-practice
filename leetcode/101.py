# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True

        left = root.left
        right = root.right

        def dfs(n1, n2):
            if n1 is None and n2 is None:
                return True
            if n1 is None or n2 is None or n1.val != n2.val:
                return False

            return dfs(n1.left, n2.right) and dfs(n1.right, n2.left)

        return dfs(left, right)









