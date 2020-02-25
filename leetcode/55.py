class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        length = len(nums)
        if length == 0:
            return False
        if length == 1:
            return True

        max_step = nums[0]
        curr_step = 0
        while curr_step <= max_step and curr_step < length:
            # print(curr_step, curr_step + nums[curr_step])
            max_step = max(max_step, curr_step + nums[curr_step])
            curr_step += 1
        # print(max_step)
        return length <= max_step + 1
