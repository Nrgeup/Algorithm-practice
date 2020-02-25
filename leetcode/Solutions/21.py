# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        ans_h = ListNode(0)
        ans_c = ans_h

        while True:
            if l1 is None and l2 is None:
                break
            if l1 is None:
                ans_c.next = l2
                break
            if l2 is None:
                ans_c.next = l1
                break

            if l1.val <= l2.val:
                val_c = l1.val
                l1 = l1.next
            else:
                val_c = l2.val
                l2 = l2.next
            tmp_n = ListNode(val_c)
            ans_c.next = tmp_n
            ans_c = tmp_n
        return ans_h.next

