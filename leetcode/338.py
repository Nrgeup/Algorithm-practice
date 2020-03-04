class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        if num == 0:
            return [0]
        ans = [0, 1]
        for i in range(2, num+1):
            ans.append(ans[int(i / 2)] + ans[i % 2])
        return ans
