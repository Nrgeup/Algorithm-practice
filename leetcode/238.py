class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        output = [1] * n
        tmp = 1
        for i in range(n):
            output[i] = tmp
            tmp *= nums[i]
        i = n - 1
        tmp = 1
        while i >= 0:
            last = nums[i]
            nums[i] = tmp
            tmp *= last
            i -= 1

        for i in range(n):
            output[i] *= nums[i]
        return output
