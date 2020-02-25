class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        利用数组自己的空间。首先扫描一遍数组，如果某个元素在1~n之间，则把它放入原数组中的i-1位置。最后扫描原数组一遍，找到第一个满足A[i] != i+1的数。
        """
        length = len(nums)
        print(nums)
        if length == 0:
            return 1
        else:
            i = 0
            while i < length:
                print(nums[i])
                if nums[i] != i + 1 and nums[i] > 0 and nums[i] <= length and nums[nums[i] - 1] != nums[i]:
                    # print("xxx")
                    tmp1 = nums[i]
                    tmp2 = nums[i] - 1
                    nums[i] = nums[tmp2]
                    nums[tmp2] = tmp1
                else:
                    i += 1
                print(nums)
            i = 0
            while i < length:
                if nums[i] != (i + 1):
                    return i + 1
                i += 1
        return length + 1


if __name__ == '__main__':
    a = Solution()
    # print(a.firstMissingPositive([1, 2, 0]))
    # print(a.firstMissingPositive([3, 4, -1, 1]))
    # print(a.firstMissingPositive([7, 8, 9, 11, 12]))
    # print(a.firstMissingPositive([2, 1]))
    # print(a.firstMissingPositive([5, 2, 3, 1]))
    # print(a.firstMissingPositive([3,4,-1,1]))
    print(a.firstMissingPositive([1]))

