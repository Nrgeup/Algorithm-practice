class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices)
        if length <= 1:
            return 0

        ans = 0
        pre_min = prices[0]
        for i in range(1, length):
            tmp_v = prices[i] - pre_min
            ans = max(tmp_v, ans)
            pre_min = min(pre_min, prices[i])
        return ans

