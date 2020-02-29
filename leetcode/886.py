class Solution(object):
    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        m = len(dislikes)
        if m <= 1 or N <= 2:
            return True

        dislike_map = {}
        for i in range(m):
            if dislikes[i][0] not in dislike_map:
                dislike_map[dislikes[i][0]] = []
            if dislikes[i][1] not in dislike_map:
                dislike_map[dislikes[i][1]] = []
            dislike_map[dislikes[i][0]].append(dislikes[i][1])
            dislike_map[dislikes[i][1]].append(dislikes[i][0])

        read_map = {}

        def dfs(name, flag):
            if name not in read_map:
                read_map[name] = flag
                for item in dislike_map[name]:
                    if not dfs(item, not flag):
                        return False
            else:
                if read_map[name] != flag:
                    return False
            return True

        for item in dislike_map:
            if item not in read_map:
                if not dfs(item, True):
                    return False

        return True

