class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s == "":
            return s

        start, end = 0, 0
        for i in range(len(s)):
            l1 = self.check(s, i, i)
            l2 = self.check(s, i, i + 1)
            l = max(l1, l2)
            if l > end - start:
                start = i - int((l - 1) / 2)
                end = i + int(l / 2)

        return s[start:end + 1]

    def check(self, s, l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return r - l - 1


