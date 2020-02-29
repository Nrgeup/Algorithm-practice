class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        n = len(nums)
        if n == 0:
            return 0
        if n <= 1:
            return nums[0]

        dp = {}
        # base case
        dp[(-2, 1)] = 0
        dp[(-1, 1)] = 0
        dp[(-1, 0)] = 0

        # dp[i, 0] = max(dp[i-1, 0], dp[i-1, 1])
        # dp[i, 1] = max(dp[i-1, 0], dp[i-2, 1])
        for i in range(n):
            dp[(i, 0)] = max(dp[(i - 1, 0)], dp[(i - 1, 1)])
            dp[(i, 1)] = max(dp[(i - 1, 0)], dp[(i - 2, 1)]) + nums[i]

        return max(dp[(n - 1, 0)], dp[(n - 1, 1)])

