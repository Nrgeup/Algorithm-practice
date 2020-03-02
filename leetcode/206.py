class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head

        prev = head
        head = head.next
        prev.next = None
        while head is not None:
            next = head.next
            head.next = prev
            prev = head
            head = next
        return prev
