// id:374639074
// runtime:84 ms
// memory:10.3 MB
// title:Sorted Matrix Search LCCI
// translatedTitle:排序矩阵查找
// questionId:1000016
// time:2022-10-19 21:53:42

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())return 0;
        const int N=matrix.size();
        const int M=matrix.front().size();
        int x=N-1,y=0;
        while(x>=0&&y<M){
            if(matrix[x][y]>target){
                x--;
            }else if(matrix[x][y]<target){
                y++;
            }else{
                return 1;
            }
        }
        return 0;
    }
};