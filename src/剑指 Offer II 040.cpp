// id:373912397
// runtime:16 ms
// memory:8.9 MB
// title:矩阵中最大的矩形
// translatedTitle:矩阵中最大的矩形
// questionId:1000284
// time:2022-10-17 19:35:01

int L[205],R[205];
vector<pair<int,int>>s;
class Solution {
public:
    int solve(const vector<int>&G){
        for(int i=0;i<G.size();i++){
            while(!s.empty()&&s.back().second>G[i]){
                R[s.back().first]=i;
                s.pop_back();
            }
            s.push_back({i,G[i]});
        }
        while(!s.empty()){
            R[s.back().first]=G.size();
            s.pop_back();
        }

        for(int i=(int)G.size()-1;i>=0;i--){
            while(!s.empty()&&s.back().second>G[i]){
                L[s.back().first]=i;
                s.pop_back();
            }
            s.push_back({i,G[i]});
        }
        while(!s.empty()){
            L[s.back().first]=-1;
            s.pop_back();
        }
        int ans=0;
        for(int i=0;i<G.size();i++){
            int l=L[i]+1,r=R[i]-1;
            ans=max(ans,G[i]*(r-l+1));
        }
        return ans;
    }
    int maximalRectangle(vector<string>& matrix) {
        if(matrix.empty())return 0;
        const int N=matrix.size();
        const int M=matrix.front().size();
        vector<vector<int>>L(N);
        for(int i=0;i<N;i++){
            L[i].resize(M);
            int now=0;
            for(int j=0;j<M;j++){
                if(matrix[i][j]=='1'){
                    if(j)L[i][j]+=L[i][j-1];
                    L[i][j]++;
                }
            }
        }
        int ans=0;
        vector<int>V;
        for(int i=0;i<M;i++){
            V.clear();
            for(int j=0;j<N;j++){
                V.push_back(L[j][i]);
            }
            ans=max(solve(V),ans);
        }
        return ans;
    }
};