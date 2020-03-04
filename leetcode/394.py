class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """

        def gen(s):
            pre = ""
            i = 0
            while i < len(s) and not (s[i] >= "0" and s[i] <= "9"):
                pre += s[i]
                i += 1
            s = s[i:]
            if s == "":
                return pre

            k = ""
            c = ""
            f = True
            n = 0
            for i in range(len(s)):
                if s[i] == "[":
                    n += 1
                    if n == 1:
                        k = int(k)
                        f = False
                        continue

                if s[i] == "]":
                    n -= 1
                    if n == 0:
                        s = s[i + 1:]
                        break

                if f:
                    k += s[i]
                else:
                    c += s[i]
            ans = pre + gen(c) * k + gen(s)
            return ans

        return gen(s)
