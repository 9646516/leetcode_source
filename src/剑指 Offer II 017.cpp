// id:373817015
// runtime:36 ms
// memory:16.3 MB
// title:含有所有字符的最短字符串
// translatedTitle:含有所有字符的最短字符串
// questionId:1000253
// time:2022-10-17 15:02:59

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>G(255);
        for(char i:t)G[i]++;
        int pos=0;
        string ans;
        string ch=t;
        sort(ch.begin(),ch.end());
        ch.resize(unique(ch.begin(),ch.end())-ch.begin());
        auto ok=[&](){
            bool ok=1;
            for(char i:ch){
                if(G[i]>0){
                    ok=0;
                    break;
                }
            }
            return ok;
        };
        for(int i=0;i<s.size();i++){
            while(pos<s.size()){
                if(ok())break;
                G[s[pos]]--;
                pos++;
            }
            if(ok()){
                if(ans.empty()||pos-i<ans.size())ans=s.substr(i,pos-i);
            }
            G[s[i]]++;
        }
        return ans;
    }
};