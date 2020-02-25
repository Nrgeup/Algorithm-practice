class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        char_stack = []
        if s is "":
            return True
        char_dict = {
            '(': ')',
            '[': ']',
            '{': '}',
        }
        for item in s:
            # print(item, char_stack)
            if item in char_dict:
                char_stack.append(char_dict[item])
            else:
                if len(char_stack) == 0 or char_stack[-1] != item:
                    return False
                else:
                    del char_stack[-1]
        if len(char_stack) > 0:
            return False
        return True
