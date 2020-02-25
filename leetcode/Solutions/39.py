import copy

class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans_list = []
        if len(candidates) == 0:
            return ans_list

        candidates.sort()
        if candidates[0] > target:
            return ans_list
        # print(candidates, target)
        ll = len(candidates)

        def dfs(sum_c, list_n, start_i):
            # print(sum_c, list_n)
            if sum_c >= target:
                if sum_c == target:
                    ans_list.append(copy.copy(list_n))
                return

            # for item in candidates[start_i:]:

            for k in range(start_i, ll):
                item = candidates[k]
                if item > target - sum_c:
                    break
                list_n.append(item)
                dfs(sum_c + item, list_n, k)
                del list_n[-1]
        dfs(0, [], 0)
        return ans_list



if __name__ == '__main__':
    a = Solution()
    print(a.combinationSum([2, 3, 6, 7], 7))
    # print(a.combinationSum([2, 6, 7, 3], 7))
    print(a.combinationSum([2, 3, 7], 8))
    print(a.combinationSum([2, 3, 5], 8))

