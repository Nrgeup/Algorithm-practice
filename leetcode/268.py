class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        begin = 0
        end = length - 1
        while begin <= end:
            if nums[begin] > begin:
                if nums[begin] == end + 1:
                    tmp = nums[begin]
                    nums[begin] = nums[end]
                    nums[end] = tmp
                    end -= 1
                else:
                    tmp = nums[nums[begin]]
                    nums[nums[begin]] = nums[begin]
                    nums[begin] = tmp
            else:
                begin += 1

        return begin

    # [3, 0, 1] -> [1, 0, 3] -> [0, 1, 3]

if __name__ == '__main__':
    a = Solution()
    print(a.missingNumber([9,6,4,2,3,5,7,0,1]))

