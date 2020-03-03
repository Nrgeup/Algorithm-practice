class Solution(object):
    def pancakeSort(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        n = len(A)

        def reverse(i, N):
            l1 = N[:i + 1]
            l2 = N[i + 1:]
            l1.reverse()
            B = l1 + l2
            return B

        def dfs(i, N):
            if i == -1 or i == 0:
                return []
            max_i = N[0]
            index_i = 0
            for j in range(i + 1):
                if N[j] >= max_i:
                    max_i = N[j]
                    index_i = j
            op_list = []
            if index_i != i and index_i != 0:
                op_list = [index_i + 1, i + 1]
                N = reverse(index_i, N)
                N = reverse(i, N)
            if index_i == 0:
                op_list = [i + 1]
                N = reverse(i, N)

            op_list += dfs(i - 1, N)
            return op_list

        return dfs(n - 1, A)
