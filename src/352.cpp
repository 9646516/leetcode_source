// id:309579220
// runtime:36 ms
// memory:32.5 MB
// title:Data Stream as Disjoint Intervals
// translatedTitle:将数据流变为多个不相交区间
// questionId:352
// time:2022-05-05 19:51:05

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
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 */

class SummaryRanges {
  public:
    set<pair<int, int>> st;
    SummaryRanges() {}

    bool exist(int val) {
        auto ptr = st.upper_bound({val, INF});
        if (ptr == st.begin())
            return false;
        ptr--;
        return ptr->first <= val && ptr->second >= val;
    }
    void addNum(int val) {
        if (exist(val))
            return;
        bool f1 = exist(val - 1);
        bool f2 = exist(val + 1);
        // cout << val << ' ' << f1 << ' ' << f2 << endl;
        if (f1 && f2) {
            auto L = --st.upper_bound({val - 1, INF});
            auto R = --st.upper_bound({val + 1, INF});
            int lb = L->first;
            int rb = R->second;
            st.erase(L);
            st.erase(R);
            st.insert({lb, rb});
        } else if (f1) {
            auto L = --st.upper_bound({val - 1, INF});
            int lb = L->first;
            st.erase(L);
            st.insert({lb, val});
        } else if (f2) {
            auto R = --st.upper_bound({val + 1, INF});
            int rb = R->second;
            st.erase(R);
            st.insert({val, rb});
        } else {
            st.insert({val, val});
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for (auto i : st) {
            ret.push_back({i.first, i.second});
        }
        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

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