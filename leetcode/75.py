class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        length = len(nums)
        index0, index1 = 0, length - 1
        index = 0
        while index < length:
            if nums[index] == 0:
                if index0 < index:
                    tmp = nums[index0]
                    nums[index0] = 0
                    index0 += 1
                    nums[index] = tmp
                else:
                    index += 1
            elif nums[index] == 2:
                if index1 > index:
                    tmp = nums[index1]
                    nums[index1] = 2
                    index1 -= 1
                    nums[index] = tmp
                else:
                    index += 1
            else:
                index += 1

