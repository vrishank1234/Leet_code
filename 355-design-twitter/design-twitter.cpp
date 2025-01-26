class Twitter {
private:
    struct Tweet {
        int id;
        int timestamp;
        Tweet* next;

        Tweet(int tweetId, int time) : id(tweetId), timestamp(time), next(nullptr) {}
    };

    unordered_map<int, Tweet*> userTweets;        // User -> Head of their tweets
    unordered_map<int, unordered_set<int>> followers; // User -> Set of followees
    int timestamp;                                // Global timestamp

public:
    Twitter() : timestamp(0) {}

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        Tweet* newTweet = new Tweet(tweetId, timestamp++);
        if (userTweets[userId] != nullptr) {
            newTweet->next = userTweets[userId];
        }
        userTweets[userId] = newTweet;
    }

    /** Retrieve the 10 most recent tweet IDs in the user's news feed. */
    vector<int> getNewsFeed(int userId) {
        // Priority queue to store the 10 most recent tweets
        auto comp = [](Tweet* a, Tweet* b) { return a->timestamp < b->timestamp; };
        priority_queue<Tweet*, vector<Tweet*>, decltype(comp)> pq(comp);

        // Add the user's tweets
        if (userTweets[userId] != nullptr) {
            pq.push(userTweets[userId]);
        }

        // Add tweets from followees
        if (followers.count(userId)) {
            for (int followeeId : followers[userId]) {
                if (userTweets[followeeId] != nullptr) {
                    pq.push(userTweets[followeeId]);
                }
            }
        }

        // Retrieve the 10 most recent tweets
        vector<int> result;
        while (!pq.empty() && result.size() < 10) {
            Tweet* topTweet = pq.top();
            pq.pop();
            result.push_back(topTweet->id);
            if (topTweet->next != nullptr) {
                pq.push(topTweet->next);
            }
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
