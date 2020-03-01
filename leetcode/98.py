# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        def dfs(node):
            min_v, max_v = node.val, node.val
            if node.left is not None:
                [a, b, c] = dfs(node.left)
                if not a or c >= node.val:
                    return [False, min_v, max_v]
                else:
                    min_v = b
            if node.right is not None:
                a, b, c = dfs(node.right)
                if not a or b <= node.val:
                    return [False, min_v, max_v]
                else:
                    max_v = c
            return [True, min_v, max_v]

        if root is not None:
            return dfs(root)[0]

        return True


