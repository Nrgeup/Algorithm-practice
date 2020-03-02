class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """

        dp = {}
        # base case
        # dp[0, i] = 1
        # dp[i, 0] = 1

        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        if n == 0:
            return 0
        max_l = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '0':
                    dp[i, j] = 0
                else:
                    if i == 0 or j == 0:
                        dp[i, j] = 1
                    else:
                        dp[i, j] = min(dp[i - 1, j - 1], dp[i, j - 1], dp[i - 1, j]) + 1
                max_l = max(max_l, dp[i, j])
        return max_l * max_l

