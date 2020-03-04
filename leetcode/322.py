class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """

        coins.sort()
        m = len(coins)
        if m == 0:
            return -1

        memo = {}
        memo[0] = 0
        for item in coins:
            memo[item] = 1

        def dp(n):
            if n not in memo:
                i = 0
                ans = float('INF')
                flag = False
                while i < m and n >= coins[i]:
                    tmp = dp(n - coins[i])
                    if tmp != -1:
                        flag = True
                        ans = min(tmp + 1, ans)
                    i += 1
                if not flag:
                    memo[n] = -1
                else:
                    memo[n] = ans
            return memo[n]

        return dp(amount)


if __name__ == '__main__':
    a = Solution()
    print(a.coinChange([1, 2, 5], 11))
    print(a.coinChange([186,419,83,408], 6249))
    print(a.coinChange([1, 2147483647], 2))