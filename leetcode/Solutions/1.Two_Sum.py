class Solution1(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]


class Solution2(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Add in hash table
        nums_dict = {}
        for i in range(len(nums)):
            current_num = nums[i]
            possible_num = target - current_num
            if possible_num in nums_dict:
                return [nums_dict[possible_num], i]
            nums_dict[nums[i]] = i



