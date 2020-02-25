class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        # print(nums, target)
        if len(nums) == 0 or target < nums[0] or target > nums[-1]:
            return [-1, -1]

        begin = 0
        end = len(nums)
        left_i = -1
        while begin < end:
            # print(begin, end)
            if nums[begin] == nums[end - 1]:
                if nums[begin] == target:
                    left_i = begin
                break

            mid = int((begin + end - 1) / 2)
            if nums[mid] < target:
                begin = mid + 1
            elif nums[mid] > target:
                end = mid
            else:
                end = mid + 1
        # print("left_i", left_i)
        if left_i == -1:
            right_i = -1
        else:
            begin = 0
            end = len(nums)
            right_i = -1
            while begin < end:
                # print(begin, end)
                if nums[begin] == nums[end - 1]:
                    if nums[begin] == target:
                        right_i = end - 1
                    break

                mid = int((begin + end) / 2)
                if nums[mid] < target:
                    begin = mid + 1
                elif nums[mid] > target:
                    end = mid
                else:
                    begin = mid

        return [left_i, right_i]


if __name__ == '__main__':
    a = Solution()
    print(a.searchRange([5, 7, 7, 8, 8, 10], 8))
    print(a.searchRange([1, 4], 4))



