import copy


class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m = len(word1)
        n = len(word2)

        if n == 0:
            return m
        if m == 0:
            return n

        dp = [i for i in range(n + 1)]

        for i in range(1, m + 1):
            # print(dp)
            tmp = copy.copy(dp)
            dp[0] = i
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[j] = tmp[j - 1]
                else:
                    dp[j] = min(dp[j] + 1, dp[j - 1] + 1)
                    dp[j] = min(dp[j], tmp[j - 1] + 1)

        return dp[n]



