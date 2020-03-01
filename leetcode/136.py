class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        map_dict = {}
        for i in nums:
            if i not in map_dict:
                map_dict[i] = 1
            else:
                del map_dict[i]

        return map_dict.keys()[0]

    def singleNumber3(self, nums):
        # sum(a)
        # a is the list , it adds up all the numbers in the
        # list a and takes start to be 0, so returning
        # only the sum of the numbers in the list.
        # sum(a, start)
        # this returns the sum of the list + start
        # set(list): remove the duplicate
        return 2 * sum(set(nums)) - sum(nums)

    def singleNumber4(self, nums):
        """
        Because a⊕0=a and a⊕a=0
        Then: a⊕b⊕a=(a⊕a)⊕b=0⊕b=b
        :param nums:
        :return:
        """
        a = 0
        for i in nums:
            a ^= i
        return a