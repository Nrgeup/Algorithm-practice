class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits) == 0:
            return []
        ans_list = []
        digit_dict = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z'],
        }

        def dfs(str_i, digits_i):
            if len(digits_i) == 0:
                ans_list.append(str_i)
                return
            curr_i = digits_i[0]
            for char_i in digit_dict[curr_i]:
                dfs(str_i+char_i, digits_i[1:])

        dfs("", digits)

        return ans_list








if __name__ == '__main__':
    a = Solution()
    print(a.letterCombinations("23"))


