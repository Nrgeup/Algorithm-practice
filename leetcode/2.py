# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import copy


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head_node = ListNode(0)
        cur_node = head_node
        overflow = 0
        while True:
            if l1 is not None:
                overflow += l1.val
                l1 = l1.next
            if l2 is not None:
                overflow += l2.val
                l2 = l2.next

            cur_node.val = overflow % 10
            overflow = int(overflow / 10)  # 0

            if l1 is None and l2 is None:
                if overflow != 0:
                    new_node = ListNode(overflow)
                    cur_node.next = new_node
                return head_node
            else:
                new_node = ListNode(overflow)
                cur_node.next = new_node
                cur_node = new_node