class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m = len(board)
        k = len(word)
        if k == 0:
            return True
        if m == 0:
            return False
        n = len(board[0])

        flag_map = [[0] * n for _ in range(m)]

        def dfs(i, j, next_i):
            if next_i == k:
                return True
            if i < 0 or j < 0 or i >= m or j >= n or flag_map[i][j] == 1 or board[i][j] != word[next_i]:
                return False

            flag_map[i][j] = 1
            if dfs(i - 1, j, next_i + 1) or dfs(i + 1, j, next_i + 1) \
                    or dfs(i, j - 1, next_i + 1) or dfs(i, j + 1, next_i + 1):
                return True
            flag_map[i][j] = 0
            return False

        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False


