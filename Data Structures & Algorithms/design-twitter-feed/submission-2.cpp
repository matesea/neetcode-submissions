class Twitter {
    unordered_map<int,unordered_set<int>> following;
    unordered_map<int,deque<pair<int,int>>> posts;
    int count;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_front({count++, tweetId});
        if (posts[userId].size() > 10)
            posts[userId].pop_back();
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        if (posts.find(userId) != posts.end() && posts[userId].size() > 0)
            pq.push({posts[userId].front().first, posts[userId].front().second, userId, 0});
        for (auto& user: following[userId]) {
            if (posts[user].size() > 0 && user != userId)
                pq.push({{posts[user].front().first, posts[user].front().second, user, 0}});
        }
        vector<int> res;
        while (res.size() < 10 && pq.size() > 0) {
            vector<int> _element = pq.top();
            int _count = _element[0], _post = _element[1], _user = _element[2], _idx = _element[3];
            pq.pop();
            res.push_back(_post);
            if (_idx+1 < posts[_user].size())
                pq.push({posts[_user][_idx+1].first, posts[_user][_idx+1].second, _user, _idx+1});
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
