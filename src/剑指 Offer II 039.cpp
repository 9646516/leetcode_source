// id:373907302
// runtime:104 ms
// memory:62.9 MB
// title:直方图最大矩形面积
// translatedTitle:直方图最大矩形面积
// questionId:1000283
// time:2022-10-17 19:20:11

int R[100005],L[100005];
vector<pair<int,int>>s;
class Solution {
public:
    int largestRectangleArea(vector<int>& V) {
        const int N=V.size();
        for(int i=0;i<N;i++){
            while(!s.empty()&&s.back().second>V[i]){
                R[s.back().first]=i;
                s.pop_back();
            }
            s.emplace_back(i,V[i]);
        }
        while(!s.empty()){
            R[s.back().first]=N;
            s.pop_back();
        }
        for(int i=N-1;i>=0;i--){
            while(!s.empty()&&s.back().second>V[i]){
                L[s.back().first]=i;
                s.pop_back();
            }
            s.emplace_back(i,V[i]);
        }
        while(!s.empty()){
            L[s.back().first]=-1;
            s.pop_back();
        }
        int ans=0;
        for(int i=0;i<N;i++){
            int l=L[i]+1,r=R[i]-1;
            ans=max(ans,V[i]*(r-l+1));
        }
        return ans;
    }
};