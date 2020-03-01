# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []
        ans_list = []
        stack = [root]
        while len(stack) > 0:
            tmp = stack.pop()
            if isinstance(tmp, TreeNode):
                if tmp.right is not None:
                    stack.append(tmp.right)
                stack.append(tmp.val)
                if tmp.left is not None:
                    stack.append(tmp.left)
            else:
                ans_list.append(tmp)
        return ans_list
