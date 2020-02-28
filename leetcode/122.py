class Solution(object):
    def maxProfit(self, prices):
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
            print(i, prices[i], dp[(i, 0)], dp[(i, 1)] )
        return dp[(length - 1, 0)]

if __name__ == '__main__':
    a = Solution()
    a.maxProfit([7,1,5,3,6,4])
    input("=====")
    a.maxProfit([1,2,3,4,5])


