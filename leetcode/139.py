class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        n = len(s)
        if len(wordDict) == 0:
            return False
        memo = {}

        def dfs(i):
            if i >= n:
                return True
            if i not in memo:
                for item in wordDict:
                    begin = 0
                    j = i
                    flag = True
                    while begin < len(item):
                        # print(begin, j)
                        if j < n and s[j] == item[begin]:
                            begin += 1
                            j += 1
                        else:
                            flag = False
                            break
                    if flag and dfs(j):
                        return True
                    memo[i] = False
            return memo[i]

        return dfs(0)



