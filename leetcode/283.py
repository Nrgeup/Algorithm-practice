class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n > 1:
            p0 = 0
            for i in range(n):
                if nums[i] != 0:
                    tmp = nums[i]
                    nums[i] = nums[p0]
                    nums[p0] = tmp
                    p0 += 1
