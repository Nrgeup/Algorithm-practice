class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        for i in range(n):
            tmp = abs(nums[i]) - 1
            if nums[tmp] > 0:
                nums[tmp] = - nums[tmp]
        ans = []
        for i in range(n):
            if nums[i] > 0:
                ans.append(i + 1)
        return ans



