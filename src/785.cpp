// id:88368417
// runtime:48 ms
// memory:11.4 MB
// title:Is Graph Bipartite?
// translatedTitle:判断二分图
// questionId:801
// time:2020-07-16 15:36:26

class Solution {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        vector<int> color(graph.size(), -1);
        queue<int> q;
        int vis = 0;
        while (vis != graph.size()) {
            for (int i = 0; i < (int)graph.size(); i++) {
                if (color[i] == -1) {
                    color[i] = 0;
                    q.push(i);
                    break;
                }
            }
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                vis++;
                int p = color[now] ^ 1;
                for (int i : graph[now]) {
                    if (color[i] == -1) {
                        color[i] = p;
                        q.push(i);
                    } else if (color[i] != p)
                        return false;
                }
            }
        }
        return true;
    }
};