# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import copy


class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        n = len(preorder)
        if n == 0:
            return None

        stack = []

        def dfs(pre_list, in_list):
            m = len(pre_list)
            if m == 0:
                return None
            head_node = TreeNode(pre_list[0])
            if m == 1:
                return head_node
            k = 0
            while k < m:
                if in_list[k] == pre_list[0]:
                    break
                k += 1

            left_node = dfs(copy.copy(pre_list[1:k + 1]), copy.copy(in_list[0:k]))
            right_node = None
            if k + 1 < m:
                right_node = dfs(copy.copy(pre_list[k + 1:]), copy.copy(in_list[k + 1:]))

            head_node.left = left_node
            head_node.right = right_node

            return head_node

        return dfs(preorder, inorder)



