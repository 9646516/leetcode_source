// id:374610006
// runtime:4 ms
// memory:7.1 MB
// title:Eight Queens LCCI
// translatedTitle:八皇后
// questionId:100233
// time:2022-10-19 20:37:02

int y[10];
int X1[20],X2[20];
int N;
vector<vector<string>>ans;
vector<int>now;
class Solution {
public:
    void dfs(int pos){
        if(pos==N){
            vector<string>V(N,string(N,'.'));
            for(int i=0;i<N;i++){
                V[i][now[i]]='Q';
            }
            ans.emplace_back(move(V));
        }
        for(int i=0;i<N;i++){
            if(!y[i]&&!X1[pos+i]&&!X2[N+pos-i]){
                now.push_back(i);
                y[i]=X1[pos+i]=X2[N+pos-i]=1;
                dfs(pos+1);
                y[i]=X1[pos+i]=X2[N+pos-i]=0;
                now.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        now.clear();
        ans.clear();
        N=n;
        memset(y,0,sizeof(y));
        memset(X1,0,sizeof(X1));
        memset(X2,0,sizeof(X2));
        dfs(0);
        return ans;
    }
};