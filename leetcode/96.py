class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = {}
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2

        if n <= 2:
            return dp[n]

        for i in range(3, n + 1):
            c_sum = 0
            for j in range(1, i + 1):
                left = dp[j - 1]
                right = dp[i - j]
                c_sum += left * right
            dp[i] = c_sum

        return dp[n]


