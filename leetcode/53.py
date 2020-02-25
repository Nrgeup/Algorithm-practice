class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 1:
            return nums[0]

        max_v = nums[0]
        last_v = nums[0]
        for i in range(1, length):
            last_v = max(nums[i], last_v + nums[i])
            max_v = max(max_v, last_v)
        return max_v
