class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        length = len(points)
        if length == 1 or length == 0:
            return length

        def takeSecond(elem):
            return elem[1]

        points.sort(key=takeSecond)
        arrows_n = 0
        start = points[0][0] - 1

        for i in range(length):
            if points[i][0] > start:
                arrows_n += 1
                start = points[i][1]

        return arrows_n





