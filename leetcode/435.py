class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """

        length = len(intervals)
        if length == 1 or length == 0:
            return 0

        def takeSecond(elem):
            return elem[1]

        intervals.sort(key=takeSecond)

        ans_n = 0
        begin = intervals[0][0]
        for i in range(length):
            if intervals[i][0] >= begin:
                begin = intervals[i][1]
            else:
                ans_n += 1
        return ans_n


