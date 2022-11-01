// id:374628918
// runtime:28 ms
// memory:20.1 MB
// title:Group Anagrams LCCI
// translatedTitle:变位词组
// questionId:1000040
// time:2022-10-19 21:26:31

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<uint64_t,vector<string>>mp;
        for(auto&i:strs){
            vector<int>cnt(26);
            for(int j:i)cnt[j-'a']++;
            uint64_t H=0;
            for(int i:cnt)H=H*233+i;
            mp[H].push_back(i);
        }
        vector<vector<string>>ret;
        for(auto&&[a,b]:mp){
            ret.push_back(b);
        }
        return ret;
    }
};