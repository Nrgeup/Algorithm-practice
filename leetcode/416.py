class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        s = sum(nums)
        if s % 2 != 0:
            return False

        s = s / 2
        n = len(nums)

        dp = [0] * (s + 1)
        dp[0] = 1
        for i in range(n):
            j = s
            while j >= nums[i]:
                dp[j] = dp[j] or dp[j - nums[i]]
                j -= 1

        return dp[s]

    def canPartition_dfs(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums = sorted(nums)
        s = sum(nums)
        if s % 2 != 0:
            return False

        s = s / 2

        n = len(nums)

        memo = {}

        def dfs(i, s_c):
            if s_c == s:
                return True
            if s_c > s:
                return False
            if (i, s_c) not in memo:
                flag = False
                for k in range(i, n):
                    if dfs(i + 1, s_c) or dfs(i + 1, s_c + nums[i]):
                        flag = True
                        break
                memo[i, s_c] = flag
            return memo[i, s_c]

        return dfs(0, 0)


if __name__ == '__main__':
    a = Solution()
    print(a.canPartition([1, 3, 3, 3, 6, 8]))