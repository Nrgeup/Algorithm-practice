# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """

        def dfs(n, d):
            ans_str = ''

            if n is None:
                return ans_str
            ans_str += str(n.val)
            ans_str += '[' + str(d) + ']'
            ans_str += dfs(n.left, d + 1)
            ans_str += '[' + str(d) + ']'
            ans_str += dfs(n.right, d + 1)
            return ans_str

        return dfs(root, 0)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """

        def dfs(s, d):
            if s == '':
                return None
            flag = '[' + str(d) + ']'
            [val, left, right] = s.split(flag)
            root = TreeNode(int(val))
            root.left = dfs(left, d + 1)
            root.right = dfs(right, d + 1)
            return root

        return dfs(data, 0)

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))


