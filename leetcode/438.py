class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        l_s = len(s)
        l_p = len(p)
        # print(s, p)
        if l_s < l_p or l_p == 0 or l_s == 0:
            return []

        need_dict = {}
        for c in p:
            if c not in need_dict:
                need_dict[c] = 0
            need_dict[c] += 1

        begin = 0
        end = 0
        ans_list = []
        match = 0
        while end < l_s:
            # print(s[begin:end + 1], match)
            # print(need_dict)
            if s[end] in need_dict:
                need_dict[s[end]] -= 1
                if need_dict[s[end]] >= 0:
                    match += 1
            end += 1

            while match == l_p:
                # print("-----------")
                # print(s[begin:end + 1], match)
                # print(need_dict)
                if end - begin == l_p:
                    ans_list.append(begin)

                if s[begin] in need_dict:
                    need_dict[s[begin]] += 1
                    if need_dict[s[begin]] > 0:
                        match -= 1
                begin += 1

        return ans_list



if __name__ == '__main__':
    a = Solution()
    print(a.findAnagrams("abacbabc", "abc"))
















