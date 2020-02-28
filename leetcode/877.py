class Solution(object):
    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        length = len(piles)
        if length == 0:
            return False

        # dp[i, j] = max(dp[i + 1, j] + piles[i], dp[i, j - 1] + piles[j])

        dp = {}
        begin = length - 1
        while begin >= 0:
            end = begin
            while end <= length - 1:
                if begin == end:
                    dp[begin, end] = piles[end]
                else:
                    dp[begin, end] = max(
                        dp[begin + 1, end] + piles[begin],
                        dp[begin, end - 1] + piles[end]
                    )
                end += 1
            begin -= 1

        return dp[0, length - 1] > max(dp[1, length - 1], dp[0, length - 2])


