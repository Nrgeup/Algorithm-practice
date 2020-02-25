class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        *** idea ***
        首先我们观察到如果给定的序列已经是完全降序的话，则没有下一个更大的排列了，因此，我们需要找到从右边开始找到两个连续的数 a[i] 和 a[i - 1]，现在，所有在 a[i - 1] 右边的数都是降序排列，不可能在其右边找到更大的排列了，所以我们需要重新组合包括 a[i - 1] 在内的其右边的所有元素。

        那么，怎么样重新组合呢，我们需要找到一个刚好比这一个排列大一点点的排列，因此，我们需要在 a[i - 1] 右边找到只比其大一点点的元素 a[j]，交换这两个元素，然后将 a[i - 1] 右边的元素逆序即可。
        """
        l = len(nums)
        i = l - 1
        while i > 0:
            if nums[i] > nums[i - 1]:
                break
            i -= 1

        if i != 0:
            j = i
            min_v = nums[i]
            min_i = i
            while j < l:
                if nums[j] > nums[i - 1] and nums[j] <= min_v:
                    min_v = nums[j]
                    min_i = j
                j += 1
            tmp = nums[min_i]
            nums[min_i] = nums[i - 1]
            nums[i - 1] = tmp
        # print(nums)
        mid_l = int((l + i - 1) / 2)
        # print(mid_l)
        j = i
        while j <= mid_l:
            tmp = nums[j]
            nums[j] = nums[l - j + i - 1]
            nums[l - j + i - 1] = tmp

            j += 1
        return

if __name__ == '__main__':
    a = Solution()
    nums = [2,3,1,3,3]
    print(nums)
    a.nextPermutation(nums)
    print(nums)