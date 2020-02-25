class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        pare_list = []

        def dfs(str_c, pare_stack):
            # print(str_c, pare_stack)
            if len(str_c) + pare_stack == 2 * n:
                str_ans = str_c + ')' * pare_stack
                pare_list.append(str_ans)
                return

            # add new '('
            dfs(str_c + '(', pare_stack + 1)

            # pop '('
            if pare_stack > 0:
                dfs(str_c + ')', pare_stack - 1)

        dfs('', 0)
        return pare_list
