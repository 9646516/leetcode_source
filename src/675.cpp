// id:371971718
// runtime:1268 ms
// memory:161.9 MB
// title:Cut Off Trees for Golf Event
// translatedTitle:为高尔夫比赛砍树
// questionId:675
// time:2022-10-11 16:43:25

/// 9646516

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3F3F3F3F;
const int maxn = 2e5 + 555;
const int MOD = 1e9 + 7;
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(const char s) { return string(1, s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N> string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A> string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B> string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) +
           ")";
}
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) +
           ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef RINNE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:\t", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
 */
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
class Solution {
  public:
    int cutOffTree(vector<vector<int>> &forest) {
        const int N = forest.size();
        const int M = forest.front().size();
        queue<tuple<int, int, int>> st;
        int dis[51][51];
        auto calc = [&](int x, int y, int x2, int y2) -> int {
            memset(dis, 0x3f, sizeof(dis));
            while (!st.empty()) {
                st.pop();
            }

            dis[x][y] = 0;
            st.push({0, x, y});
            while (!st.empty()) {
                auto [d, x, y] = st.front();
                st.pop();
                if (x == x2 && y == y2)
                    break;
                if (dis[x][y] < d)
                    continue;
                for (int i = 0; i < 4; i++) {
                    int x2 = x + dx[i];
                    int y2 = y + dy[i];
                    if (x2 >= 0 && x2 < N && y2 >= 0 && y2 < M) {
                        if (forest[x2][y2] != 0) {
                            if (dis[x2][y2] > d + 1) {
                                dis[x2][y2] = d + 1;
                                st.push({d + 1, x2, y2});
                            }
                        }
                    }
                }
            }
            return dis[x2][y2];
        };
        vector<tuple<int, int, int>> V;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (forest[i][j] > 1) {
                    V.emplace_back(forest[i][j], i, j);
                }
            }
        }
        sort(V.begin(), V.end());
        int x = 0, y = 0;
        int ans = 0;
        for (auto &[idx, x2, y2] : V) {
            int D = calc(x, y, x2, y2);
            // cout << x << ' ' << y << ' ' << x2 << ' ' << y2 << ' ' << D << endl;
            if (D == INF)
                return -1;
            ans += D;
            x = x2;
            y = y2;
        }
        return ans;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{};
    Solution s;
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif