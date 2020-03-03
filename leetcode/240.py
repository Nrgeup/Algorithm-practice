class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        if n == 0:
            return False

        def dfs(x1, y1, x2, y2):
            if x1 > x2 or y1 > y2 or matrix[x1][y1] > target \
                    or matrix[x2][y2] < target:
                return False
            if matrix[x1][y1] == target or matrix[x2][y2] == target:
                return True
            if x1 == x2 and y1 == y2:
                return matrix[x1][y1] == target

            mid_x = int((x1 + x2) / 2)
            mid_y = int((y1 + y2) / 2)

            return dfs(x1, y1, mid_x, mid_y) or \
                   dfs(x1, mid_y + 1, mid_x, y2) or \
                   dfs(mid_x + 1, y1, x2, mid_y) or \
                   dfs(mid_x + 1, mid_y + 1, x2, y2)

        return dfs(0, 0, m - 1, n - 1)
