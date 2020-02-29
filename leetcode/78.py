import copy


class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans_list = []
        n = len(nums)

        def dfs(c_nums, i):
            if i == n:
                ans_list.append(copy.copy(c_nums))
                return
            dfs(c_nums, i + 1)
            c_nums.append(nums[i])
            dfs(c_nums, i + 1)
            del c_nums[-1]
            return

        if n > 0:
            dfs([], 0)
        else:
            ans_list = [[]]
        return ans_list

