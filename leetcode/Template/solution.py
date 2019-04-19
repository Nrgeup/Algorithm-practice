# The following is for running in the local environment, do not submit to Leetcode.
import os

####### Once you are ready, please submit the following. #######

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        min_num = min(nums)
        max_num = max(nums)



        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]


############################  END  ############################

if __name__ == '__main__':
    read_from_file = False
    my_model = Solution()

    test_cases = []
    if not read_from_file:
        test_cases = [
            [
                [2, 7, 11, 15], 9
            ]
        ]
    else:
        # Load from file
        pass


    for print_i in range(len(test_cases)):
        print("=" * 8, print_i, "=" * 8)
        [nums, target] = test_cases[print_i]

        print("nums:", nums)
        print("target:", target)
        output = my_model.twoSum(nums, target)
        print("output:", output)
