class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        stack_n = 0
        max_l = 0
        curr_l = 0

        for char in s:
            # print(char)
            if char == '(':
                stack.append("(")
                stack_n += 1
            else:
                if stack_n > 0:
                    stack_n -= 1
                    tmp_v = 0
                    while stack[-1] != '(':
                        tmp_v += stack[-1]
                        del stack[-1]
                    stack[-1] = tmp_v + 2
                # print(stack)
                else:
                    curr_l = 0
                    for item in stack:
                        if item == '(':
                            curr_l = 0
                        else:
                            curr_l += item
                            max_l = max(curr_l, max_l)
                    stack = []
        curr_l = 0
        for item in stack:
            if item == '(':
                curr_l = 0
            else:
                curr_l += item
                max_l = max(curr_l, max_l)
        return max_l


if __name__ == '__main__':
    a = Solution()
    print(a.longestValidParentheses("()(()"))
    print(a.longestValidParentheses(")()())"))
    print(a.longestValidParentheses("(()()"))
    print(a.longestValidParentheses(")()())()()("))