class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        length = len(intervals)
        if length == 0:
            return []
        if length == 1:
            return intervals

        def take_first(elem):
            return elem[0]

        # print(intervals)
        intervals.sort(key=take_first)
        # print(intervals)

        stack_list = [intervals[0]]

        for i in range(1, length):
            # stack_list[-1] & intervals[i]
            tmp = intervals[i]
            while len(stack_list) > 0 and stack_list[-1][1] >= tmp[0]:
                tmp = [stack_list[-1][0], max(tmp[1], stack_list[-1][1])]
                del stack_list[-1]
            stack_list.append(tmp)

        return stack_list
