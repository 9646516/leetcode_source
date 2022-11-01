// id:369168733
// runtime:32 ms
// memory:12.8 MB
// title:Maximum Sum of an Hourglass
// translatedTitle:沙漏的最大总和
// questionId:2508
// time:2022-10-02 10:36:06

const int dy[] = {-1, -1, 0, 0, 0, 1, 1};
const int dx[] = {-1, 1, -1, 0, 1, -1, 1};
class Solution {
  public:
    int maxSum(vector<vector<int>> &grid) {
        const int N = grid.size();
        const int M = grid.front().size();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int xs = 0;
                bool ok = 1;
                for (int k = 0; k < 7; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && y >= 0 && x < N && y < M) {
                        xs += grid[x][y];
                    } else {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    ans = max(ans, xs);
                }
            }
        }
        return ans;
    }
};