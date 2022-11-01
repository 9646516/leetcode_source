// id:374593753
// runtime:0 ms
// memory:6.6 MB
// title:Hanota LCCI
// translatedTitle:汉诺塔问题
// questionId:1000015
// time:2022-10-19 19:53:43

class Solution {
public:
    void solve(int N,vector<int>& A, vector<int>& B, vector<int>& C) {
        if(N>0){
            solve(N-1,A,C,B);
            C.push_back(A.back());
            A.pop_back();
            solve(N-1,B,A,C);
        }
    }
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        solve(A.size(),A,B,C);
    }
};