class Solution(object):
    def isMatch0(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        import re
        c = re.match(p, s)
        if c is not None and c.span() == (0, len(s)):
            return True
        else:
            return False

    def isMatch1(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """

        if not p:
            return not s

        first_match = bool(s) and p[0] in {s[0], '.'}

        if len(p) >= 2 and p[1] == '*':
            if self.isMatch(s, p[2:]):  # zero p[0]
                return True
            else:
                # many p[0]
                return first_match and self.isMatch(s[1:], p)
        else:
            return first_match and self.isMatch(s[1:], p[1:])

    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        vec = {}
        return self.dp(0, 0, s, p, vec)

    def dp(self, i, j, s, p, vec):
        """ if s[i:] and p[j:] match?"""
        if (i, j) not in vec:
            if j == len(p):
                # If go to the end?
                ans = i == len(s)
            else:
                first_match = i < len(s) and p[j] in {s[i], '.'}
                if j + 1 < len(p) and p[j + 1] == '*':
                    ans = self.dp(i, j + 2, s, p, vec) or \
                          (first_match and self.dp(i + 1, j, s, p, vec))
                else:
                    ans = first_match and self.dp(i + 1, j + 1, s, p, vec)
            vec[i, j] = ans
        return vec[i, j]

