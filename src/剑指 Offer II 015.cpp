// id:373811494
// runtime:8 ms
// memory:8.5 MB
// title:字符串中的所有变位词
// translatedTitle:字符串中的所有变位词
// questionId:1000251
// time:2022-10-17 14:49:03

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>G(26);
        vector<int>ret;
        int pos=0;
        for(char i:p)G[i-'a']++;
        for(int i=0;i<s.size();i++){
            G[s[i]-'a']--;
            if(i>=p.size()){
                G[s[pos]-'a']++;
                pos++;
            }
            int ok=1;
            for(int i=0;i<26;i++){
                if(G[i]){
                    ok=0;break;
                }
            }
            if(ok)ret.push_back(i-p.size()+1);
        }
        return ret;
    }
};