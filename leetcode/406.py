class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """

        people = sorted(people, key=lambda x: (x[0], -x[1]))

        n = len(people)
        if n == 1:
            return people

        ans_list = [0] * n
        for item in people:
            i = 0
            m = item[1]
            while i < n:
                if ans_list[i] == 0:
                    if m == 0:
                        break
                    m -= 1
                i += 1
            ans_list[i] = item
        return ans_list