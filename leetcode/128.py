class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums_dict = {}

        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return 1

        for i in range(n):
            nums_dict[nums[i]] = 0
        max_inter = 1
        for i in range(n):
            tmp_v = nums[i]
            if tmp_v in nums_dict:
                last_v = tmp_v - 1
                while last_v in nums_dict:
                    del nums_dict[last_v]
                    last_v -= 1
                next_v = tmp_v + 1
                while next_v in nums_dict:
                    del nums_dict[next_v]
                    next_v += 1

                max_inter = max(max_inter, next_v - last_v - 1)

        return max_inter




