class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        if m == 1:
            return sum(grid[0])
        n = len(grid[0])
        if n == 1:
            return sum([grid[k][0] for k in range(m)])

        map_dict = {}
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    map_dict[i, j] = grid[i][j]
                else:
                    if i == 0:
                        map_dict[i, j] = grid[i][j] + map_dict[i, j - 1]
                    elif j == 0:
                        map_dict[i, j] = grid[i][j] + map_dict[i - 1, j]
                    else:
                        map_dict[i, j] = grid[i][j] + min(map_dict[i - 1, j], map_dict[i, j - 1])

        return map_dict[m - 1, n - 1]


