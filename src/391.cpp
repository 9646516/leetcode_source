// id:311001441
// runtime:104 ms
// memory:31.7 MB
// title:Perfect Rectangle
// translatedTitle:完美矩形
// questionId:391
// time:2022-05-08 23:14:24

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
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 */
struct Line {
    int down;
    int top;
    int x;
    int type;
    friend bool operator<(const Line &lhs, const Line &rhs) {
        if (lhs.x != rhs.x) {
            return lhs.x < rhs.x;
        } else {
            return lhs.type < rhs.type;
        }
    }
};
class Solution {
  public:
    bool isRectangleCover(vector<vector<int>> &X) {
        int left = INF;
        int right = -INF;
        int down = INF;
        int top = -INF;
        ll sum = 0;
        vector<Line> V;
        for (auto &i : X) {
            left = min(left, i[0]);
            down = min(down, i[1]);
            right = max(right, i[2]);
            top = max(top, i[3]);
            sum += 1LL * (i[2] - i[0]) * (i[3] - i[1]);
            V.push_back(Line{i[1], i[3], i[0], 1});
            V.push_back(Line{i[1], i[3], i[2], 0});
        }
        if (1LL * (right - left) * (top - down) != sum)
            return false;
        sort(V.begin(), V.end());
        multiset<pair<int, int>> st;
        for (auto &i : V) {
            if (i.type) {
                auto p = st.lower_bound({i.down, INF});
                if (p != st.end()) {
                    if (p->first < i.top) {
                        return false;
                    }
                }
                if (p != st.begin()) {
                    p--;
                    if (p->second > i.down) {
                        return false;
                    }
                }
                st.insert({i.down, i.top});
            } else {
                st.erase({i.down, i.top});
            }
        }

        return true;
    }
};
//[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
    Solution s;
    auto res = s.isRectangleCover(data);
    debug(res);
    return 0;
}
#endif