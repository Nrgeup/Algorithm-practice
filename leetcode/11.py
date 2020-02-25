class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        def area(i, j):
            return min(height[i], height[j]) * (j - i)

        begin = 0
        end = n-1
        max_area = 0
        while begin < end:
            """
            *** proof ***
            case1: hi <= hj
                area(i, j)  = min(hi, hj)*(j-i)
                            = hi*(j-i)
                            > hi*(k-i)
                            > min(hi, hk)*(k-i)
                            > area(i, k)
            case2: hi > hj
                area(i, j)  = min(hi, hj)*(j-i)
                            = hj*(j-i)
                            > hj*(j-k)
                            > min(hj, hk)*(j-k)
                            > area(k, j)
            """
            max_area = max(max_area, area(begin, end))
            if height[begin] <= height[end]:
                begin += 1
            else:
                end -= 1
        return max_area




    def maxArea0(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        def value(i, j):
            return min(height[i], height[j]) * (j - i)
        max_v = value(0, 1)
        for i in range(2, n):
            for k in range(0, i):
                max_v = max(value(k, i), max_v)
        return max_v