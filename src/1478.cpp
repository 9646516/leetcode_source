// id:78741679
// runtime:168 ms
// memory:7.9 MB
// title:Allocate Mailboxes
// translatedTitle:安排邮筒
// questionId:1571
// time:2020-06-14 00:36:08

class Solution {
  public:
    int minDistance(vector<int> &houses, int K) {
        sort(houses.begin(), houses.end());
        static int dp[105][105], a[105], cost[105][105];
        const int N = houses.size();
        for (int i = 0; i < N; i++) {
            a[i + 1] = houses[i];
        }
        memset(dp, 0x3F, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                auto f = [&](int x) {
                    int cost = 0;
                    for (int jb = i; jb <= j; jb++) {
                        cost += abs(a[jb] - x);
                    }
                    return cost;
                };
                int L = a[i], R = a[j];
                while (L + 3 <= R) {
                    int lmid = L + (R - L) / 3;
                    int rmid = R - (R - L) / 3;
                    if (f(lmid) > f(rmid))
                        L = lmid;
                    else
                        R = rmid;
                }
                int c = numeric_limits<int>::max();
                for (int jb = L; jb <= R; jb++) {
                    c = min(c, f(jb));
                }
                cost[i][j] = c;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                for (int k = 1; i + k <= N; k++) {
                    dp[i + k][j + 1] = min(dp[i + k][j + 1], dp[i][j] + cost[i + 1][i + k]);
                }
            }
        }
        return dp[N][K];
    }
};