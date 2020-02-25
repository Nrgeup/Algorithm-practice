import copy


class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        length = len(nums)
        if length == 0:
            return []
        if length == 1:
            return [nums]
        ans_list = []

        def dfs(num_list, c_nums):
            if len(num_list) == length:
                ans_list.append(copy.copy(num_list))
                return

            for i in range(len(c_nums)):
                tmp_nums = copy.copy(c_nums)
                del tmp_nums[i]
                num_list.append(c_nums[i])
                dfs(num_list, tmp_nums)
                del num_list[-1]

        dfs([], nums)
        return ans_list