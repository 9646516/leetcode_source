// id:374214129
// runtime:8 ms
// memory:7 MB
// title:翻转字符
// translatedTitle:翻转字符
// questionId:1000269
// time:2022-10-18 17:09:50

int s0[200005];
int s1[200005];
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        const int N=s.size();
        s0[0]=s[0]=='1';
        for(int i=1;i<N;i++){
            s0[i]=s0[i-1]+(s[i]=='1');
        }
        s1[N-1]=s[N-1]=='0';
        for(int i=N-2;i>=0;i--){
            s1[i]=s1[i+1]+(s[i]=='0');
        }
        int ans=1e9;
        for(int i=0;i<N;i++){
            int cost=0;
            if(i)cost+=s0[i-1];
            if(i!=N-1)cost+=s1[i+1];
            ans=min(ans,cost);
        }
        return ans;
    }
};