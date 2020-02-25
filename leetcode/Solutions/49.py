class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        n = len(strs)
        if n == 0:
            return []
        if n == 1:
            return [strs]

        str_set = {}

        for item in strs:
            str_list = [i for i in item]
            str_list.sort()
            # print(str_list)
            str_index = ''.join(str_list)
            if str_index not in str_set:
                str_set[str_index] = []
                # print(str_index)
            str_set[str_index].append(item)

        ans = []
        for item in str_set:
            ans.append(str_set[item])
        return ans


