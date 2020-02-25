class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        ans = 0
        i = 0
        map_char = {}
        for j in range(length):
            if s[j] in map_char:
                i = max(map_char[s[j]], i)
            ans = max(ans, j - i + 1)
            map_char[s[j]] = j + 1

        return ans
    