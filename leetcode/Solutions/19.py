# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        n_stack = []

        node = head
        while True:
            n_stack.append(node)
            if len(n_stack) > n + 1:
                del n_stack[0]

            if node.next is None:
                break
            else:
                node = node.next

        if n == 1:
            if len(n_stack) < 2:
                return None
            n_stack[-2].next = None
        elif len(n_stack) < n + 1:  # head
            head = head.next
        else:
            n_stack[0].next = n_stack[2]

        return head
