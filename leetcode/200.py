class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        max_n = 0
        m = len(grid)
        if m == 0:
            return 0

        n = len(grid[0])
        if n == 0:
            return 0

        def dfs(i, j):
            grid[i][j] = '0'
            if i - 1 >= 0 and grid[i-1][j] == '1':
                dfs(i-1, j)
            if i + 1 < m and grid[i+1][j] == '1':
                dfs(i+1, j)
            if j - 1 >= 0 and grid[i][j-1] == '1':
                dfs(i, j-1)
            if j + 1 < n and grid[i][j+1] == '1':
                dfs(i, j+1)

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    max_n += 1
                    dfs(i, j)

        return max_n
