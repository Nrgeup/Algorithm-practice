class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        wait_list = {s:0}
        success_list = {}
        while len(wait_list.keys()) > 0:
            fail_list = {}
            for item in wait_list:
                n = 0
                for i in range(len(item)):
                    if item[i] != '(' and item[i] != ')':
                        continue
                    new_str = item[:i] + item[i + 1:]
                    fail_list[new_str] = 0
                    if item[i] == '(':
                        n += 1
                    if item[i] == ')':
                        n -= 1
                    if n < 0:
                        break
                if n == 0 and item not in success_list:
                    success_list[item] = 0
            if len(success_list.keys()) > 0:
                return list(success_list.keys())
            wait_list = fail_list

        return ['']

    def removeInvalidParentheses_TLE(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        memo = {}

        def check(s):
            if s not in memo:
                ans = False
                n = 0
                for i in s:
                    if i == '(':
                        n += 1
                    if i == ')':
                        n -= 1
                    if n < 0:
                        break
                if n == 0:
                    ans = True
                memo[s] = ans
            return memo[s]

        def get(s):
            h = ''
            for i in s:
                if i == '(' or i == ')':
                    h += i
            return h

        if check(get(s)):
            return [s]

        pro_list = [s]
        while len(pro_list) > 0:
            fail_list = []
            success_list = []
            for item in pro_list:
                left_part = ''
                right_part = item
                while right_part != '':
                    v = right_part[0]
                    right_part = right_part[1:]
                    new_str = left_part + right_part
                    if check(get(new_str)):
                        if new_str not in success_list:
                            success_list.append(new_str)
                    else:
                        if new_str not in fail_list:
                            fail_list.append(new_str)
                    left_part += v
            if len(success_list) > 0:
                break
            pro_list = fail_list

        return success_list

if __name__ == '__main__':
    # "()())()"
    # "(a)())()"
    # ")("
    # "()(((((((()"
    # ")(((()(y((u()(z()()"
    a = Solution()
    print(a.removeInvalidParentheses(")(((()(y((u()(z()()"))


