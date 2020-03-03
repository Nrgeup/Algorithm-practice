class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        memo = {}
        n_list = []
        i = 1
        while i * i <= n:
            memo[i*i] = 1
            n_list.append(i*i)
            i += 1
        def dfs(k):
            if k not in memo:
                n_min = float('INF')
                for item in n_list:
                    if item > k:
                        break
                    n_min = min(n_min, dfs(k-item) + 1)
                memo[k] = n_min
            return memo[k]
        return dfs(n)
