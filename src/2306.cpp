// id:354385541
// runtime:844 ms
// memory:72.8 MB
// title:Naming a Company
// translatedTitle:公司命名
// questionId:2390
// time:2022-08-24 17:08:46

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
 * @lc app=leetcode.cn id=2306 lang=cpp
 *
 * [2306] 公司命名
 */

class Solution {
  public:
    uint64_t H(const string &x) {
        uint64_t ret = 0;
        for (auto i : x) {
            ret = ret * 233 + i;
        }
        return ret;
    }
    long long distinctNames(vector<string> &ideas) {
        unordered_set<uint64_t> st;
        static uint64_t POW[50000 + 555];
        POW[0] = 1;
        for (int i = 1; i <= 50000; i++)
            POW[i] = POW[i - 1] * 233;
        int cnt[30];
        int cnt2[30][30];
        memset(cnt, 0, sizeof(cnt));
        memset(cnt2, 0, sizeof(cnt2));
        for (auto &i : ideas) {
            st.insert(H(i));
            cnt[i[0] - 'a']++;
        }
        for (auto &i : ideas) {
            uint64_t P = H(i.substr(1));
            for (int j = 'a'; j <= 'z'; j++) {
                uint64_t HH = j * POW[(int)i.size() - 1] + P;
                if (st.count(HH)) {
                    cnt2[i[0] - 'a'][j - 'a']++;
                }
            }
        }
        ll ans = 0;
        ll ans2 = 0;

        for (const auto &i : ideas) {
            uint64_t P = H(i.substr(1));
            for (int j = 'a'; j <= 'z'; j++) {
                uint64_t HH = j * POW[(int)i.size() - 1] + P;
                if (st.count(HH)) {
                    if (j == i[0]) {
                        ans += cnt[j - 'a'] - 1;
                        ans2 += cnt2[j - 'a'][i[0] - 'a'] - 1;
                    } else {
                        ans += cnt[j - 'a'];
                        ans2 += cnt2[j - 'a'][i[0] - 'a'];
                    }
                }
            }
        }
        ans = ans + ans - ans2;

        ll n = ideas.size();
        return n * (n - 1) - ans;
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