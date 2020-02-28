class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        length = len(nums)
        if length == 0:
            return 0
        if length == 1:
            return 1

        status = []
        for i in range(length):
            # print(status)
            begin = 0
            end = len(status)

            while begin < end:
                mid = int((begin + end - 1) / 2)

                if status[mid] > nums[i]:
                    end = mid
                elif status[mid] < nums[i]:
                    begin = mid + 1
                else:
                    end = mid

            if begin > len(status) - 1:
                status.append(nums[i])
            else:
                status[begin] = nums[i]

        return len(status)

    def lengthOfLIS2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        length = len(nums)
        if length == 0:
            return 0
        if length == 1:
            return 1

        dp = [1] * length
        max_l = 1

        for i in range(1, length):
            j = i - 1
            while j >= 0:
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
                j -= 1
            # print(i, dp[i])
            max_l = max(max_l, dp[i])
        return max_l



