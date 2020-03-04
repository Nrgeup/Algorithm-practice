import heapq


class MedianFinder(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.l_len = 0
        self.r_len = 0
        self.l_list = []  # min heap
        self.r_list = []  # max heap

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        if self.l_len == 0:
            heapq.heappush(self.l_list, (-num, num))
            self.l_len += 1
            return

        left_top = self.l_list[0]
        if num <= left_top[1]:
            heapq.heappush(self.l_list, (-num, num))
            self.l_len += 1
        else:
            heapq.heappush(self.r_list, (num, num))
            self.r_len += 1

        while self.l_len > self.r_len + 1:
            v = heapq.heappop(self.l_list)
            heapq.heappush(self.r_list, (v[1], v[1]))
            self.l_len -= 1
            self.r_len += 1

        while self.l_len + 1 < self.r_len:
            v = heapq.heappop(self.r_list)
            heapq.heappush(self.l_list, (-v[0], v[1]))
            self.l_len += 1
            self.r_len -= 1
        return

    def findMedian(self):
        """
        :rtype: float
        """
        if self.l_len == 0 and self.r_len == 0:
            return None
        if self.l_len == self.r_len:
            return float((self.l_list[0][1] + self.r_list[0][1]) / 2.0)
        if self.l_len > self.r_len:
            return float(self.l_list[0][1])
        else:
            return float(self.r_list[0][1])

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

