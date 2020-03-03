class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        n = len(nums)
        begin = 1
        end = n - 1
        while begin <= end:
            mid = int((begin + end) / 2)
            k = 0
            for item in nums:
                if item <= mid and item >= begin:
                    k += 1
            if k > mid - begin + 1:
                if begin == mid:
                    return begin
                end = mid
            else:
                begin = mid + 1
