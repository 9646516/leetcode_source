// id:84796967
// runtime:112 ms
// memory:14.2 MB
// title:Count Submatrices With All Ones
// translatedTitle:统计全 1 子矩形
// questionId:1628
// time:2020-07-05 11:11:43

class Solution {
  public:
    int numSubmat(vector<vector<int>> &mat) {
        vector<vector<int>> sum = mat;
        const int N = sum.size(), M = sum.front().size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (j && mat[i][j])
                    mat[i][j] = mat[i][j - 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int now = mat[i][j];
                for (int k = i; k >= 0; k--) {
                    now = min(now, mat[k][j]);
                    ans += now;
                }
            }
        }
        return ans;
    }
};