# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """

        def dfs(node):
            # return head_node end_node
            end = node

            left_node = node.left
            right_node = node.right

            if left_node is not None:
                [h1, e1] = dfs(left_node)
                end.left = None
                end.right = h1
                end = e1

            if right_node is not None:
                [h2, e2] = dfs(right_node)
                end.left = None
                end.right = h2
                end = e2

            return [node, end]

        if root is not None:
            return dfs(root)[0]
        return None
