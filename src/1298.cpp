// id:367132375
// runtime:108 ms
// memory:39.7 MB
// title:Maximum Candies You Can Get from Boxes
// translatedTitle:你能从盒子里获得的最大糖果数
// questionId:1424
// time:2022-09-25 21:35:43

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
 * @lc app=leetcode.cn id=1298 lang=cpp
 *
 * [1298] 你能从盒子里获得的最大糖果数
 */

class Solution {
  public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys,
                   vector<vector<int>> &containedBoxes, vector<int> &initialBoxes) {
        unordered_set<int> box, key;
        queue<int> q;
        for (int i : initialBoxes) {
            if (status[i]) {
                q.push(i);
            } else {
                box.insert(i);
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            ans += candies[now];
            for (int i : keys[now]) {
                if (box.count(i)) {
                    box.erase(i);
                    q.push(i);
                } else {
                    key.insert(i);
                }
            }
            for (int i : containedBoxes[now]) {
                if (status[i]) {
                    q.push(i);
                } else if (key.count(i)) {
                    key.erase(i);
                    q.push(i);
                } else {
                    box.insert(i);
                }
            }
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