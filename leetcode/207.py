class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        in_num = [0] * numCourses
        link_map = {}
        for item in prerequisites:
            if item[0] not in link_map:
                link_map[item[0]] = []
            link_map[item[0]].append(item[1])
            in_num[item[1]] += 1

        while True:
            flag = True
            for i in range(numCourses):
                if in_num[i] == 0:
                    in_num[i] = -1
                    flag = False
                    break
            if flag:
                return False
            if i in link_map:
                for item in link_map[i]:
                    in_num[item] -= 1
                del link_map[i]
            if len(link_map.keys()) == 0:
                break
        return True

