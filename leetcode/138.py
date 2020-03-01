"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """

        node_map = {}

        def dfs(n):
            if n is None:
                return None
            if n not in node_map:
                new_node = Node(n.val)
                node_map[n] = new_node

                new_node.next = dfs(n.next)
                new_node.random = dfs(n.random)

            return node_map[n]

        return dfs(head)










