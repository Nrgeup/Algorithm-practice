# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0

        max_v = [root.val]

        def dfs(n):
            left_v = 0
            if n.left is not None:
                left_v = dfs(n.left)
            right_v = 0
            if n.right is not None:
                right_v = dfs(n.right)

            val = max(left_v + n.val, right_v + n.val, n.val)
            max_v[0] = max(max_v[0], left_v + right_v + n.val)
            max_v[0] = max(max_v[0], val)
            return val

        dfs(root)
        return max_v[0]





