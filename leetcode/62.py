class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m == 1 or n == 1:
            return 1

        map_dict = {}
        i = m - 1
        while i >= 0:
            j = n - 1
            while j >= 0:
                if i == m - 1:
                    map_dict[i, j] = 1
                else:
                    map_dict[i, j] = map_dict[i + 1, j]
                    if j != n - 1:
                        map_dict[i, j] += map_dict[i, j + 1]
                j -= 1
            i -= 1
        return map_dict[0, 0]