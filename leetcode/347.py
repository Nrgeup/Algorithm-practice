class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        nums_dict = {}
        for item in nums:
            if item not in nums_dict:
                nums_dict[item] = 0
            nums_dict[item] += 1

        nums_list = []
        for key in nums_dict:
            nums_list.append((key, nums_dict[key]))

        def take_second(elem):
            return elem[1]

        nums_list.sort(key=take_second, reverse=True)
        ans = []
        for i in range(k):
            ans.append(nums_list[i][0])
        return ans
