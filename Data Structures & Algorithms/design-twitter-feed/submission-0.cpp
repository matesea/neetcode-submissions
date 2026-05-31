class Twitter {
    unordered_map<int,unordered_set<int>> following;
    deque<pair<int,int>> posts;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_front({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        for (auto [user, post]: posts) {
            if (user == userId || following[userId].find(user) != following[userId].end()) {
                res.push_back(post);
            }
            if (res.size() == 10)
                break;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
       following[followerId].erase(followeeId) ;
    }
};
