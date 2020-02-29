class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        length = len(prices)
        if length <= 1:
            return 0

        dp = {}
        # base case
        dp[(-1, 0)] = 0
        dp[(-2, 0)] = 0
        dp[(-1, 1)] = - float("INF")
        dp[(-2, 1)] = - float("INF")

        # dp[(i, 0)] = max(dp[i-1, 0], dp[i-1, 1] + prices[i])
        # dp[(i, 1)] = max(dp[i-1, 1], dp[i-2, 0] - prices[i])

        for i in range(length):
            dp[(i, 0)] = max(dp[(i - 1, 0)], dp[(i - 1, 1)] + prices[i])
            dp[(i, 1)] = max(dp[(i - 1, 1)], dp[(i - 2, 0)] - prices[i])

        return dp[(length - 1, 0)]


