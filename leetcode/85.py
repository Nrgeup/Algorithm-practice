import copy


class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        if n == 0:
            return 0

        last_v = [0] * n
        max_area = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == "1":
                    last_v[j] += 1
                else:
                    last_v[j] = 0
            print(last_v)
            max_area = max(max_area, self.largestRectangleArea(copy.copy(last_v)))
            print(max_area)

        return max_area

    def largestRectangleArea(self, hei):
        hei.append(0)
        max_area = 0
        stack = []
        for i in range(len(hei)):
            while len(stack) > 0 and hei[stack[-1]] > hei[i]:
                tmp = stack.pop()
                if len(stack) > 0:
                    max_area = max(max_area, hei[tmp] * (i - stack[-1] - 1))
                else:
                    max_area = max(max_area, hei[tmp] * i)
            stack.append(i)
        return max_area


