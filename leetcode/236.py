# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        ans_node = [root]

        def dfs(n):
            if n is None:
                return 0
            left_v = 0
            if n.left is not None:
                left_v = dfs(n.left)
            if left_v == -1:
                return -1
            right_v = 0
            if n.right is not None:
                right_v = dfs(n.right)
            if right_v == -1:
                return -1

            if n.val == p.val or n.val == q.val:
                if right_v == 0 and left_v == 0:
                    return 1
                else:
                    ans_node[0] = n
                    return -1
            else:
                if right_v == 1 and left_v == 1:
                    ans_node[0] = n
                    return -1
                elif right_v == 1 or left_v == 1:
                    return 1
                else:
                    return 0

        dfs(root)
        return ans_node[0]
