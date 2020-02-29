from collections import deque

class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        begin = 0
        end = 0
        data_list = deque([])

        output = []
        while end < len(nums):
            while len(data_list) > 0 and data_list[-1] < nums[end]:
                data_list.pop()
            data_list.append(nums[end])

            if end - begin + 1 == k:
                output.append(data_list[0])
                if nums[begin] == data_list[0]:
                    data_list.popleft()
                begin += 1
            end += 1

        return output


if __name__ == '__main__':
    a = Solution()
    print(a.maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3))

