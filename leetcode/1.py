class Solution(object):
    def twoSum(self, nums, target):
        """
        Hash map
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_dict = {}
        for index, num_1 in enumerate(nums):
            num_2 = target - num_1
            if num_2 in nums_dict:
                return [nums_dict[num_2], index]
            nums_dict[num_1] = index


    def twoSum1(self, nums, target):
        """
        Enumerate
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = len(nums)
        for i in range(l):
            for j in range(i + 1, l):
                if nums[i] + nums[j] == target:
                    return [i, j]
                    break




