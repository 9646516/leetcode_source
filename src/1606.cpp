// id:364741725
// runtime:676 ms
// memory:174.8 MB
// title:Find Servers That Handled Most Number of Requests
// translatedTitle:找到处理最多请求的服务器
// questionId:1710
// time:2022-09-19 15:16:13

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
 * @lc app=leetcode.cn id=1606 lang=cpp
 *
 * [1606] 找到处理最多请求的服务器
 */
struct node {
    int time;
    int opt;
    int idx;
    friend bool operator<(const node &a, const node &b) {
        if (a.time != b.time)
            return a.time < b.time;
        else
            return a.opt < b.opt;
    }
    node(int time, int opt, int idx) {
        this->time = time;
        this->opt = opt;
        this->idx = idx;
    }
};

class Solution {
  public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
        multiset<node> st;
        for (int i = 0; i < arrival.size(); i++) {
            st.insert(node(arrival[i], 1, i));
        }
        vector<int> cnt(k);
        set<int> waiting;
        for (int i = 0; i < k; i++) {
            waiting.insert(i);
        }
        while (!st.empty()) {
            auto now = *st.begin();
            st.erase(st.begin());
            if (now.opt == 1) {
                if (waiting.empty()) {
                    continue;
                } else {
                    auto pos = waiting.lower_bound(now.idx % k);
                    int select;
                    if (pos == waiting.end())
                        select = *waiting.begin();
                    else
                        select = *pos;
                    waiting.erase(select);
                    cnt[select] += 1;
                    st.insert(node(now.time + load[now.idx], -1, select));
                }
            } else {
                waiting.insert(now.idx);
            }
        }
        vector<int> ret;
        int mx = *max_element(cnt.begin(), cnt.end());
        for (int i = 0; i < (int)cnt.size(); i++) {
            if (cnt[i] == mx) {
                ret.push_back(i);
            }
        }
        return ret;
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