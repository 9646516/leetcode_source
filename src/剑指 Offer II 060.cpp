// id:373967296
// runtime:16 ms
// memory:13.2 MB
// title:出现频率最高的 k 个数字
// translatedTitle:出现频率最高的 k 个数字
// questionId:1000324
// time:2022-10-17 21:45:45

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i:nums)mp[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto &i:mp){
            q.push({i.second,i.first});
            if(q.size()>k)q.pop();
        }
        vector<int>ret;
        while(!q.empty()){
            ret.push_back(q.top().second);
            q.pop();
        }
        return ret;
    }
};