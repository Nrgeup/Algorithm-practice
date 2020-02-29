import heapq


class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.time_id = 1
        self.tweet_list = []
        self.follow_map = {}

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: None
        """
        # heapq.heappush(self.tweet_list, (- self.time_id, (userId, tweetId)))

        self.tweet_list.append([userId, tweetId])
        self.time_id += 1

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        return_tweet = []
        self.follow(userId, userId)

        end = len(self.tweet_list) - 1
        while end >= 0:
            item = self.tweet_list[end]
            if item[0] in self.follow_map[userId]:
                return_tweet.append(item[1])
                if len(return_tweet) == 10:
                    break
            end -= 1

        # for item in self.tweet_list:
        #     if item[1][0] in self.follow_map[userId]:
        #         return_tweet.append(item[1][1])
        #         if len(return_tweet) == 10:
        #             break
        return return_tweet

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        if followerId not in self.follow_map:
            self.follow_map[followerId] = [followerId]
        if followeeId not in self.follow_map[followerId]:
            self.follow_map[followerId].append(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        if followerId in self.follow_map and followeeId in self.follow_map[followerId]:
            self.follow_map[followerId].remove(followeeId)

# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)

if __name__ == '__main__':
    # pq = []
    # heapq.heappush(pq, -10)
    # heapq.heappush(pq, -5)
    # heapq.heappush(pq, -15)
    # print(pq)
    # while len(pq) > 0:
    #     print(heapq.heappop(pq))
    # x = [1, 8, -2, 23, -7, -4, 18, 23, 42, 37, 2]
    # heap = list(x)
    # heapq.heapify(heap)
    # print(heap)  # [-4, 2, 1, 23, 7, 2, 18, 23, 42, 37, 8]

    print('A'&' ')


