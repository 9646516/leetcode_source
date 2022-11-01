// id:325894819
// runtime:4 ms
// memory:6 MB
// title:Sudoku Solver
// translatedTitle:解数独
// questionId:37
// time:2022-06-16 15:30:58

class Solution {
public:
    vector<vector<char>>V;
    int row[11][11];
    int col[11][11];
    int X[11][11];
    int calcX(int i,int j){
        i/=3;
        j/=3;
        return i*3+j;
    }
    bool dfs(int i,int j){
        if(i==9)return 1;
        int nx=i,ny=j;
        ny++;
        if(ny==9){
            nx++;
            ny=0;
        }
        if(V[i][j]!='.'){
            return dfs(nx,ny);
        }else{
            for(int k=1;k<=9;k++){
                if(!row[i][k]&&!col[j][k]&&!X[calcX(i,j)][k]){
                    V[i][j]='0'+k;
                    row[i][k]=1;
                    col[j][k]=1;
                    X[calcX(i,j)][k]=1;
                    bool res=dfs(nx,ny);
                    if(res)return 1;
                    V[i][j]='.';
                    row[i][k]=0;
                    col[j][k]=0;
                    X[calcX(i,j)][k]=0;
                }
            }
            return 0;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        V=board;
        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++){
                row[i][j]=col[i][j]=X[i][j]=0;
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int idx=board[i][j]-'0';
                    row[i][idx]=1;
                    col[j][idx]=1;
                    X[calcX(i,j)][idx]=1;
                }
            }
        }
        bool res=dfs(0,0);
        cout<<res<<endl;
        board=V;
    }
};