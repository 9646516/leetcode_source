// id:374301480
// runtime:4 ms
// memory:7.2 MB
// title:Compress String LCCI
// translatedTitle:字符串压缩
// questionId:100161
// time:2022-10-18 21:31:51

class Solution {
public:
    string compressString(string S) {
        stringstream ss;
        char last=S[0];
        int cnt=1;
        for(int i=1;i<S.size();i++){
            if(S[i]==last)cnt++;
            else {
                ss<<last<<cnt;
                last=S[i];
                cnt=1;
            }
        }
        ss<<last<<cnt;
        string ans=ss.str();
        if(S.size()>ans.size())return ans;
        else return S;
    }
};