// id:373894470
// runtime:24 ms
// memory:20.5 MB
// title:变位词组
// translatedTitle:变位词组
// questionId:1000275
// time:2022-10-17 18:28:13

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<uint64_t,vector<string>>mp;
        for(auto i:strs){
            vector<int>cnt(26);
            for(int j:i){
                cnt[j-'a']++;
            }
            uint64_t H=0;
            for(int i:cnt)H=H*233+i;
            mp[H].push_back(i);
        }
        vector<vector<string>>ret;
        for(auto &&[a,b]:mp){
            ret.emplace_back(move(b));
        }
        return ret;
    }
};