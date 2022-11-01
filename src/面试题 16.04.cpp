// id:374825668
// runtime:12 ms
// memory:7.8 MB
// title:Tic-Tac-Toe LCCI
// translatedTitle:井字游戏
// questionId:100261
// time:2022-10-20 15:09:43

class Solution {
public:
    string tictactoe(vector<string>& board) {
        const int N=board.size();
        for(int i=0;i<N;i++){
            int s0=0,s1=0;
            for(int j=0;j<N;j++){
                if(board[i][j]=='O')s0++;
                else if(board[i][j]=='X')s1++;
            }
            if(s0==N)return "O";
            if(s1==N)return "X";
        }
        for(int i=0;i<N;i++){
            int s0=0,s1=0;
            for(int j=0;j<N;j++){
                if(board[j][i]=='O')s0++;
                else if(board[j][i]=='X')s1++;
            }
            if(s0==N)return "O";
            if(s1==N)return "X";
        }
        {
            int s0=0,s1=0;
            for(int j=0;j<N;j++){
                if(board[j][j]=='O')s0++;
                else if(board[j][j]=='X')s1++;
            }
            if(s0==N)return "O";
            if(s1==N)return "X";
        }
        {
            int s0=0,s1=0;
            for(int j=0;j<N;j++){
                if(board[j][N-1-j]=='O')s0++;
                else if(board[j][N-1-j]=='X')s1++;
            }
            if(s0==N)return "O";
            if(s1==N)return "X";
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]==' ')return "Pending";
            }
        }
        return "Draw";
    }
};
