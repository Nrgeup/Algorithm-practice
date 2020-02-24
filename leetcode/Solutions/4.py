class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1) > len(nums2):
            nums3 = nums1
            nums1 = nums2
            nums2 = nums3

        if len(nums1) == 0:
            return (nums2[int(len(nums2) / 2)] + nums2[int((len(nums2) - 1) / 2)]) / 2.0

        # n >= m
        m = len(nums1)
        n = len(nums2)

        # two parts
        # partA: nums1[0, i-1] + nums2[0, j-1]
        # pertB: nums1[i, m-1] + nums2[j, n-1]
        # j = (m + n + 1) / 2 - i
        # nums1[i-1] <= nums2[j] & nums2[j-1] <= nums1[i]

        i_min, i_max, mid_len = 0, m, (m + n + 1) / 2
        while i_min <= i_max:
            i = (i_min + i_max) / 2
            j = mid_len - i
            if i < m and nums2[j - 1] > nums1[i]:
                # i is too small
                i_min = i + 1
            elif i > 0 and nums1[i - 1] > nums2[j]:
                # i is too big
                i_max = i - 1
            else:
                # i is perfect
                if i == 0:
                    max_of_left = nums2[j - 1]
                elif j == 0:
                    max_of_left = nums1[i - 1]
                else:
                    max_of_left = max(nums1[i - 1], nums2[j - 1])

                if (m + n) % 2 == 1:
                    return max_of_left

                if i == m:
                    min_of_right = nums2[j]
                elif j == n:
                    min_of_right = nums1[i]
                else:
                    min_of_right = min(nums1[i], nums2[j])

                return (max_of_left + min_of_right) / 2.0

