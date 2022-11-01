// id:354480238
// runtime:408 ms
// memory:181.8 MB
// title:Count Integers in Intervals
// translatedTitle:统计区间中的整数数目
// questionId:2357
// time:2022-08-24 21:29:02

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
 * @lc app=leetcode.cn id=2276 lang=cpp
 *
 * [2276] 统计区间中的整数数目
 */

class CountIntervals {
  public:
    int cnt = 0;
    set<pair<int, int>> st;
    CountIntervals() {}
    void add(int l, int r) {
        auto pos = st.upper_bound({l, -1});
        while (pos != st.begin() && prev(pos)->second >= l) {
            auto pre = prev(pos);
            l = min(l, pre->first);
            r = max(r, pre->second);
            cnt -= pre->second - pre->first + 1;
            st.erase(pre);
            pos = st.upper_bound({l, -1});
        }
        while (pos != st.end() && r >= pos->first) {
            l = min(l, pos->first);
            r = max(r, pos->second);
            cnt -= pos->second - pos->first + 1;
            st.erase(pos);
            pos = st.upper_bound({l, -1});
        }
        st.insert({l, r});
        cnt += r - l + 1;
    }

    int count() { return cnt; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{};
    CountIntervals *s = new CountIntervals();
    s->add(571, 770);
    s->add(920, 996);
    s->add(65, 512);
    s->add(959, 959);
    s->add(313, 330);
    s->add(473, 928);
    debug(s->count());
    return 0;
}
#endif