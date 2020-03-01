class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        n = len(heights)
        if n == 0:
            return 0
        if n == 1:
            return heights[0]

        max_area = 0
        heights.append(0)
        stack = []  # store the index
        # print(heights)
        # print(stack)
        for i in range(len(heights)):
            while len(stack) > 0 and heights[stack[-1]] > heights[i]:
                j = stack.pop()
                if len(stack) == 0:
                    l = i
                else:
                    l = i - stack[-1] - 1
                max_area = max(max_area, heights[j] * l)
            stack.append(i)
            # print([heights[i] for i in stack], max_area)
        return max_area

    def largestRectangleArea_dp(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        n = len(heights)
        if n == 0:
            return 0
        if n == 1:
            return heights[0]
        memo = {}

        def dp(i, j):
            if j == i:
                return [heights[i], heights[j]]
            if (i, j) not in memo:
                min_h1, max_area1 = dp(i + 1, j)
                min_h2, max_area2 = dp(i, j - 1)
                min_h = min(min_h1, min_h2)
                max_area = max(max_area1, max_area2, min_h * (j - i + 1))
                memo[i, j] = [min_h, max_area]
            return memo[i, j]

        return dp(0, n-1)[1]


if __name__ == '__main__':
    # a = []
    # print(a.empty())
    a = Solution()
    print(a.largestRectangleArea([4,2,0,3,2,4,3,4]))
    print(a.largestRectangleArea([2,1,5,6,2,3]))