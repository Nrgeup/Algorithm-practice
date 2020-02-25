class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """

        if n == 1 or n == 2:
            return n
        a = [1, 2]
        i = 2
        while i < n:
            a.append(a[i - 1] + a[i - 2])
            i += 1
        return a[n - 1]


