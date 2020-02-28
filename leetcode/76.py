class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        t_dict = {}
        for i in t:
            if i not in t_dict:
                t_dict[i] = 0
            t_dict[i] += 1

        l_t = len(t)
        l_s = len(s)
        if l_s == 0 or l_t == 0 or l_t > l_s:
            return ""

        min_l = l_s
        min_str = ""
        begin = 0
        end = 0
        counter = len(t)
        while end < l_s:
            if s[end] in t_dict:
                t_dict[s[end]] -= 1
                if t_dict[s[end]] >= 0:
                    counter -= 1
            # print(s[begin: end + 1], counter)
            # print(t_dict)
            while counter == 0:
                # print("===", s[begin])
                # print(t_dict)
                if s[begin] in t_dict:
                    t_dict[s[begin]] += 1
                    if t_dict[s[begin]] > 0:
                        # print("++++", s[begin: end + 1])
                        # print(t_dict)
                        counter += 1
                        curr_l = end - begin + 1
                        if min_l >= curr_l:
                            min_l = curr_l
                            min_str = s[begin: end + 1]
                begin += 1

            end += 1

        return min_str

