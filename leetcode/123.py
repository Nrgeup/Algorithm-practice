class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices)
        if length <= 1:
            return 0

        max_k = 2
        dp = {}

        # base case
        for k in range(max_k):
            dp[(-1, k, 0)] = 0
            dp[(-1, k, 1)] = - float("INF")

        # dp(n, k, 0) = max(dp(n-1, k, 0), dp(n-1, k, 1) + prices[i])
        # dp(n, k, 1) = max(dp(n-1, k, 1), dp(n-1, k-1, 0) - prices[i])

        dp[(-1, -1, 0)] = 0
        dp[(-1, -1, 1)] = - float("INF")
        for i in range(length):
            dp[(i, -1, 0)] = 0
            dp[(i, -1, 1)] = - float("INF")

            for k in range(max_k):
                dp[(i, k, 0)] = max(dp[(i - 1, k, 0)], dp[(i - 1, k, 1)] + prices[i])
                dp[(i, k, 1)] = max(dp[(i - 1, k, 1)], dp[(i - 1, k - 1, 0)] - prices[i])

        return dp[(length - 1, 1, 0)]

