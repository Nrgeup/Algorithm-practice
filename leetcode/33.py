class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # print(nums, target)
        if len(nums) == 0:
            return -1

        rotate_index = 0
        if nums[0] > nums[-1]:
            begin = 0
            end = len(nums)

            while begin < end:
                mid = int((begin + end) / 2)

                if nums[mid] > nums[end - 1]:  # right part
                    if begin == mid:
                        rotate_index = end - 1
                        break
                    begin = mid
                elif nums[mid] < nums[begin]:  # let part
                    if end == mid + 1:
                        rotate_index = end - 1
                        break
                    end = mid + 1
                # print(begin, end)
        # print(rotate_index)

        plus_x = 0
        if rotate_index != 0:
            if nums[-1] == target:
                return len(nums) - 1
            elif nums[-1] > target:
                plus_x += rotate_index
                nums = nums[rotate_index:]
            else:
                nums = nums[:rotate_index]

        # print(nums)


        if target < nums[0] or target > nums[-1]:
            return -1
        begin = 0
        end = len(nums)
        ans = -1
        while begin < end:
            mid = int((begin + end) / 2)
            if nums[mid] == target:
                ans = mid
                break
            elif nums[mid] < target:
                begin = mid + 1
            else:
                end = mid
        if ans != -1:
            ans += plus_x
        return ans




if __name__ == '__main__':
    a = Solution()
    print(a.search([4, 5, 6, 7, 0, 1, 2], 5))
    print(a.search([4, 5, 6, 7, 0, 1], 0))
    print(a.search([4, 5, 6, 7, 0], 0))
    print(a.search([4, 5, 7, 0], 0))
    print(a.search([4, 7, 0], 0))
    print(a.search([4, 0], 0))
    print(a.search([4, 5, 7], 0))







