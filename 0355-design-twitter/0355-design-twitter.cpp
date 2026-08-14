class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> users;
    int time;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> q;
        for(int x:users[userId]){
            for(int i=0;i<tweets[x].size();i++){
                q.push(tweets[x][i]);
            }
        }
        for(int i=0;i<tweets[userId].size();i++){
            q.push(tweets[userId][i]);
        }
        vector<int> feed;
        while(!q.empty()&&feed.size()<10){
            pair<int,int> p=q.top();
            q.pop();
            feed.push_back(p.second);
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
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