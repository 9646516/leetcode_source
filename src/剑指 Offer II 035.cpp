// id:373895729
// runtime:4 ms
// memory:13.3 MB
// title:最小时间差
// translatedTitle:最小时间差
// questionId:1000278
// time:2022-10-17 18:34:35

class Solution {
public:
    int calc(int a,int b){
        if(a>b)swap(a,b);
        int ret=b-a;
        return min(ret,60*24-ret);
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int>V;
        for(auto i:timePoints){
            int A=i[0]-'0';
            int B=i[1]-'0';
            int C=i[3]-'0';
            int D=i[4]-'0';
            int H=A*10+B;
            int M=C*10+D;
            V.push_back(H*60+M);
        }
        sort(V.begin(),V.end());
        int ans=calc(V[0],V.back());
        for(int i=1;i<V.size();i++){
            ans=min(ans,calc(V[i],V[i-1]));
        }
        return ans;
    }
};