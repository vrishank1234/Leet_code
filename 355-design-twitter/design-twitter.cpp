class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> userTweets; // User -> [(timestamp, tweetId)]
    unordered_map<int, unordered_set<int>> followers;     // User -> Set of followees
    int timestamp;                                        // Global timestamp

public:
    /** Initialize your Twitter object. */
    Twitter() : timestamp(0) {}

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        userTweets[userId].emplace_back(timestamp++, tweetId);
    }

    /** Retrieve the 10 most recent tweet IDs in the user's news feed. */
    vector<int> getNewsFeed(int userId) {
        // Min-heap to store the 10 most recent tweets
        auto comp = [](pair<int, int>& a, pair<int, int>& b) { return a.first < b.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        // Add the user's own tweets
        if (userTweets.count(userId)) {
            for (auto& tweet : userTweets[userId]) {
                pq.push(tweet);
            }
        }

        // Add tweets from followees
        if (followers.count(userId)) {
            for (int followeeId : followers[userId]) {
                if (userTweets.count(followeeId)) {
                    for (auto& tweet : userTweets[followeeId]) {
                        pq.push(tweet);
                    }
                }
            }
        }

        // Retrieve the 10 most recent tweets
        vector<int> result;
        while (!pq.empty() && result.size() < 10) {
            result.push_back(pq.top().second); // Get tweetId
            pq.pop();
        }

        return result;
    }

    /** Follow a user. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    /** Unfollow a user. */
    void unfollow(int followerId, int followeeId) {
        if (followers.count(followerId)) {
            followers[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
