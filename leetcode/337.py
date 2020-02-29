# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0

        memo = {}

        def dp(node, rob):
            # base case
            if node is None:
                return 0

            # dp
            if (node, rob) not in memo:
                if rob == 0:
                    ans_v = max(dp(node.left, 0), dp(node.left, 1)) \
                            + max(dp(node.right, 0), dp(node.right, 1))
                else:
                    ans_v = dp(node.left, 0) + dp(node.right, 0) + node.val

                memo[node, rob] = ans_v
            return memo[node, rob]

        return max(dp(root, 0), dp(root, 1))

