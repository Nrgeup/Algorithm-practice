class Solution(object):
    def maxCoins(self, nums):
        # nums: List[int]
        # int
        n = len(nums)
        if n == 1:
            return nums[0]
        n_dict = {}
        for i in range(n):
            n_dict[i] = nums[i]

        n_dict[-1] = 1
        n_dict[n] = 1

        memo = {}
        for i in range(n):
            memo[i, i] = n_dict[i - 1] * n_dict[i] * n_dict[i + 1]

        def dp(i, j):
            if i > j:
                return 0
            if (i, j) not in memo:
                max_v = 0
                for k in range(i, j + 1):
                    tmp = dp(i, k - 1) + dp(k + 1, j) + n_dict[k] \
                          * n_dict[i - 1] * n_dict[j + 1]
                    max_v = max(max_v, tmp)
                memo[i, j] = max_v
            return memo[i, j]

        return dp(0, n - 1)


if __name__ == '__main__':
    a = Solution()
    print(a.maxCoins([3,1,5,8]))


























