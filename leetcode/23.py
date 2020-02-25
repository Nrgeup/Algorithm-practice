import heapq


class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """

        pro_queen = []

        for node in lists:
            if node is not None:
                heapq.heappush(pro_queen, (node.val, node))

        head_node = ListNode(0)
        curr_node = head_node
        while len(pro_queen) > 0:
            pop_node = heapq.heappop(pro_queen)[1]
            if pop_node.next is not None:
                heapq.heappush(pro_queen, (pop_node.next.val, pop_node.next))

            new_node = ListNode(pop_node.val)
            curr_node.next = new_node
            curr_node = new_node

        return head_node.next


