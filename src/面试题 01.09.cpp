// id:374310768
// runtime:4 ms
// memory:8.3 MB
// title:String Rotation LCCI
// translatedTitle:字符串轮转
// questionId:100162
// time:2022-10-18 21:54:38

uint64_t H[100005];
uint64_t POW[100005];

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size()!=s2.size())return 0;
        const int N=s1.size();
        if(!N)return 1;
        uint64_t res=0;
        for(char i:s2)res=res*233+i;
        POW[0]=1;
        for(int i=1;i<=N;i++)POW[i]=POW[i-1]*233;
        H[0]=s1[0];
        for(int i=1;i<N;i++){
            H[i]=H[i-1]*233+s1[i];
        }
        if(H[N-1]==res)return 1;
        for(int i=1;i<N;i++){
            uint64_t now=H[i-1]+(H[N-1]-H[i-1]*POW[N-1-i+1])*POW[i-1-0+1];
            if(now==res)return 1;
        }
        return 0;
    }
};