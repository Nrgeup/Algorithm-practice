class Solution(object):

    def superEggDrop(self, K, N):
        """
        :type K: int
        :type N: int
        :rtype: int
        """
        memo = {}

        def dp(k, n):
            if k == 1:
                return n
            if n == 0:
                return 0

            if (k, n) not in memo:
                tmp = float("INF")
                # for i in range(1, n+1):
                #     tmp = min(tmp,
                #               max(dp(k-1, i-1), dp(k, n-i)) + 1
                #              )

                begin = 1
                end = n + 1
                while begin < end:
                    mid = int((begin + end) / 2)
                    broken = dp(k - 1, mid - 1)
                    not_broken = dp(k, n - mid)
                    if broken > not_broken:
                        end = mid
                        tmp = min(tmp, broken + 1)
                    else:
                        begin = mid + 1
                        tmp = min(tmp, not_broken + 1)

                memo[k, n] = tmp

            return memo[k, n]

        return dp(K, N)
