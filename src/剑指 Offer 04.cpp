// id:373271780
// runtime:12 ms
// memory:12.6 MB
// title:二维数组中的查找 LCOF
// translatedTitle:二维数组中的查找
// questionId:100276
// time:2022-10-15 19:03:55

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& V, int target) {
        const int N=V.size();
        for(int i=0;i<N;i++){
            if(binary_search(V[i].begin(),V[i].end(),target))return 1;
        }
        return 0;
    }
};