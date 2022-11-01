// id:362985925
// runtime:812 ms
// memory:85.4 MB
// title:Closest Subsequence Sum
// translatedTitle:最接近目标值的子序列和
// questionId:1881
// time:2022-09-14 20:50:44

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
 * @lc app=leetcode.cn id=1755 lang=cpp
 *
 * [1755] 最接近目标值的子序列和
 */

class Solution {
  public:
    vector<int> gao(vector<int> &V) {
        vector<int> ret;
        function<void(int, int)> dfs = [&](int pos, int sum) {
            if (pos == V.size()) {
                ret.push_back(sum);
            } else {
                dfs(pos + 1, sum);
                dfs(pos + 1, sum + V[pos]);
            }
        };
        dfs(0, 0);
        return ret;
    }
    int minAbsDifference(vector<int> &nums, int goal) {
        vector<int> V[2];
        for (int i = 0; i < (int)nums.size(); i++) {
            V[i & 1].push_back(nums[i]);
        }
        auto a = gao(V[0]);
        auto b = gao(V[1]);
        debug(a);
        debug(b);
        set<int> st;
        for (int i : a)
            st.insert(i);
        int ans = INF;
        for (int i : b) {
            auto pos = st.lower_bound(goal - i);
            if (pos != st.begin())
                pos--;
            for (int j = 0; j < 2; j++) {
                if (pos != st.end())
                    ans = min(ans, abs(*pos + i - goal));
                else
                    break;
                pos++;
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
    vector<int> data{7, -9, 15, -2};
    Solution s;
    auto res = s.minAbsDifference(data, -5);
    debug(res);
    return 0;
}
#endif