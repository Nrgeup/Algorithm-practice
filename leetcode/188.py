class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices)
        if k == 0 or len <= 1:
            return 0

        # k = min(int(length / 2) + 1, k)
        if k > int(length / 2):
            return self.maxProfitK(prices)

        dp = {}

        # base case
        dp[(-1, -1, 0)] = 0
        dp[(-1, -1, 1)] = - float("INF")
        for j in range(k):
            dp[(-1, j, 0)] = 0
            dp[(-1, j, 1)] = - float("INF")

        # dp[i, k, 0] = max(dp[i-1, k, 0], dp[i-1, k, 1] + prices[i])
        # dp[i, k, 1] = max(dp[i-1, k, 1], dp[i-1, k-1, 0] - prices[i])
        for i in range(length):
            dp[(i, -1, 0)] = 0
            dp[(i, -1, 1)] = - float("INF")
            for j in range(k):
                dp[(i, j, 0)] = max(dp[(i - 1, j, 0)], dp[(i - 1, j, 1)] + prices[i])
                dp[(i, j, 1)] = max(dp[(i - 1, j, 1)], dp[(i - 1, j - 1, 0)] - prices[i])

        return dp[(length - 1, k - 1, 0)]

    def maxProfitK(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        print(prices)
        length = len(prices)
        if length <= 1:
            return 0

        # base
        dp = {}
        dp[(-1, 0)] = 0
        dp[(-1, 1)] = - float("INF")

        # dp[n, k, sell/buy]
        # dp[N, hold] = max(dp[N-1, hold], dp[N-1, Not-hold] - prices[N])
        # dp[N, not-hold] = max(dp[N-1, not-hold], dp[N-1, hold] + prices[N])

        for i in range(length):
            dp[(i, 0)] = max(dp[(i - 1, 0)], dp[(i - 1, 1)] + prices[i])
            dp[(i, 1)] = max(dp[(i - 1, 1)], dp[(i - 1, 0)] - prices[i])
            print(i, prices[i], dp[(i, 0)], dp[(i, 1)])
        return dp[(length - 1, 0)]

