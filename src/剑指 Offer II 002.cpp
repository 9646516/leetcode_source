// id:373791775
// runtime:0 ms
// memory:6 MB
// title:二进制加法
// translatedTitle:二进制加法
// questionId:1000231
// time:2022-10-17 13:47:15

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        const int N=max(a.size(),b.size());
        int lbit=0;
        string res;
        for(int i=0;i<N;i++){
            int B=lbit;
            if(i<a.size())B+=a[i]-'0';
            if(i<b.size())B+=b[i]-'0';
            if(B>=2){
                lbit=1;
                res.push_back(B-2+'0');
            }else{
                lbit=0;
                res.push_back(B+'0');
            }
        }
        if(lbit)res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
    }
};