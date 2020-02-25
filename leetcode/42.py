class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        if n <= 2:
            return 0
        list1 = [0] * n
        list2 = [0] * n
        max1 = 0
        max2 = 0
        i = 0
        while i < n:
            max1 = max(max1, height[i])
            max2 = max(max2, height[n-i-1])
            list1[i] = max1
            list2[n-i-1] = max2
            i += 1
        # print(height)
        # print(list1)
        # print(list2)
        ans = 0
        for i in range(n):
            ans += (min(list1[i], list2[i]) - height[i])
        return ans
