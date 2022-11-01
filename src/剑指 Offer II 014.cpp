// id:373809734
// runtime:8 ms
// memory:7 MB
// title:字符串中的变位词
// translatedTitle:字符串中的变位词
// questionId:1000250
// time:2022-10-17 14:44:22

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>G(26);
        for(auto i:s1)G[i-'a']++;
        int pos=0;
        for(int i=0;i<s2.size();i++){
            G[s2[i]-'a']--;
            while(G[s2[i]-'a']<0){
                G[s2[pos]-'a']++;
                pos++;
            }
            int ok=1;
            for(int i=0;i<26;i++){
                if(G[i]){
                    ok=0;break;
                }
            }
            if(ok)return 1;
        }
        return 0;
    }
};