// id:63960481
// runtime:576 ms
// memory:119.1 MB
// title:最小跳跃次数
// translatedTitle:最小跳跃次数
// questionId:1000090
// time:2020-04-18 19:52:53

class Solution {
  public:
    int minJump(const vector<int> &jump) {
        vector<int> vis(jump.size(), 0);
        int R = 0;
        queue<pair<int, int>> Q;
        Q.push(make_pair(0, 0));
        vis[0] = 1;
        int ans = numeric_limits<int>::max();
        while (!Q.empty()) {
            auto [dis, x] = Q.front();
            Q.pop();
            int to = x + jump[x];
            if (to >= (int)jump.size()) {
                ans = dis + 1;
                break;
            } else {
                if (!vis[to]) {
                    Q.push(make_pair(dis + 1, to));
                    vis[to] = 1;
                }
                for (; R <= x; R++) {
                    if (!vis[R]) {
                        vis[R] = 1;
                        Q.push(make_pair(dis + 1, R));
                    }
                }
            }
        }
        return ans;
    }
};
