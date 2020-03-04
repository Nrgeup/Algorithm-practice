# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import copy


class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """

        data = [sum, 0]

        def dfs(n, s):
            if n == None:
                return
            s.append(0)
            for i in range(len(s)):
                s[i] += n.val
                if s[i] == data[0]:
                    data[1] += 1
            dfs(n.left, copy.copy(s))
            dfs(n.right, copy.copy(s))

        dfs(root, [])
        return data[1]

