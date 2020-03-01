# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []

        ans_list = []
        max_deep = [-1]

        def dfs(n, d):
            if max_deep[0] < d:
                max_deep[0] = d
                ans_list.append([])

            if n.left is not None:
                dfs(n.left, d + 1)

            ans_list[d].append(n.val)

            if n.right is not None:
                dfs(n.right, d + 1)
            return

        dfs(root, 0)
        return ans_list





