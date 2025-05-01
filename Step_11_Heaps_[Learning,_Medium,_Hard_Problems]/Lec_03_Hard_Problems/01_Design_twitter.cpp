// https://leetcode.com/problems/design-twitter/

using namespace std;
#include <bits/stdc++.h>

class Twitter {
    private:
        int time;
        unordered_map<int, unordered_set<int>> mp; // Stores followers
        unordered_map<int, vector<pair<int, int>>> mp2; // Stores tweets userId -> (time, tweetId)
    public:
        Twitter() {
            time = 0;
        }
        
        void postTweet(int userId, int tweetId) {
            // mp2[userId].emplace_back(time,tweetId);
            vector<pair<int, int>> &temp = mp2[userId];
            temp.push_back(make_pair(time, tweetId));
            time++;
        }
        
        vector<int> getNewsFeed(int userId) {
            priority_queue<pair<int,int>> pq;
            for(auto i: mp2[userId]) pq.push(i);
            for(auto i: mp[userId]){
                for(auto j: mp2[i]) pq.push(j);
            }
            vector<int> feed;
            int count=10;
            while(!pq.empty() && count){
                feed.push_back(pq.top().second);
                pq.pop();
                count--;
            }
            return feed;
        }
        
        void follow(int followerId, int followeeId) {
            mp[followerId].insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            mp[followerId].erase(followeeId); 
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
    
    
     /*
     
     class Twitter {
        deque<pair<int, int>> feed;
        unordered_map<int, unordered_set<int>> follows;
    public:
        Twitter() {
            
        }
        
        void postTweet(int userId, int tweetId) {
            feed.push_back(make_pair(userId, tweetId));
        }
        
        vector<int> getNewsFeed(int userId) {
            vector<int> ans;
            unordered_set<int>& following = follows[userId];
            int count = 0;
    
            for (auto it = feed.rbegin(); it != feed.rend() && count < 10; ++it) {
                int author = it->first;
                int tweet = it->second;
    
                if (author == userId || following.count(author)) {
                    ans.push_back(tweet);
                    count++;
                }
            }
    
            return ans;
        }
        
        void follow(int followerId, int followeeId) {
            if (followerId != followeeId)
                follows[followerId].insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            follows[followerId].erase(followeeId);
        }
    };
     
     */