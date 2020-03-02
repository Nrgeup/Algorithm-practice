# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        len = 0
        begin = head
        while begin is not None:
            len += 1
            begin = begin.next

        if len == 0 or len == 1:
            return True
        mid = int(len / 2)

        right = head.next
        left = head
        left.next = None
        # print(left.val, right.val)
        for i in range(mid-1):
            tmp = right.next
            right.next = left
            left = right
            right = tmp
            # print(left.val, right.val)

        if len % 2 != 0:
            right = right.next
        while left is not None and left.val == right.val:
            right = right.next
            left = left.next
        return left is None


