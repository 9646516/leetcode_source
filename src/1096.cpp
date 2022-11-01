// id:367733695
// runtime:12 ms
// memory:11.5 MB
// title:Brace Expansion II
// translatedTitle:花括号展开 II
// questionId:1188
// time:2022-09-27 15:18:44

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
string to_string(const char s) { return "'" + string(1, s) + "'"; }
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
 * @lc app=leetcode.cn id=1096 lang=cpp
 *
 * [1096] 花括号展开 II
 */

class Solution {
    string s;
    void cat(set<string> &a, char b) {
        set<string> c;
        for (auto &i : a)
            c.insert(i + b);
        a = move(c);
    }
    void X(set<string> &a, const set<string> &b) {
        set<string> c;
        for (auto &i : a)
            for (auto &j : b)
                c.insert(i + j);
        a = move(c);
    }
    set<string> dfs(int l, int r) {
        set<string> res{""};
        for (int i = l; i <= r;) {
            if (s[i] == '{') {
                set<string> st;
                int j = i, cnt = 0;
                for (; j <= r; j++) {
                    if (s[j] == '{')
                        cnt++;
                    if (s[j] == '}')
                        cnt--;
                    if (cnt == 0)
                        break;
                }
                int pre = i + 1;
                cnt = 0;
                for (int k = i + 1; k <= j - 1; k++) {
                    if (s[k] == '{')
                        cnt++;
                    if (s[k] == '}')
                        cnt--;
                    if (s[k] == ',' && cnt == 0) {
                        for (auto &s : dfs(pre, k - 1))
                            st.insert(s);
                        pre = k + 1;
                    }
                }
                for (auto &s : dfs(pre, j - 1))
                    st.insert(s);
                X(res, st);
                i = j + 1;
            } else {
                cat(res, s[i]);
                i++;
            }
        }
        return res;
    }

  public:
    vector<string> braceExpansionII(string sb) {
        debug(sb, sb.size());
        s = sb;
        int idx = 0;
        auto res = dfs(0, sb.size() - 1);
        vector<string> ret;
        for (auto &i : res)
            ret.push_back(i);
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
    string a = "{{a,z},a{b,c},{ab,z}}";
    // string a = "{a,b}{c,{d,e}}";
    auto res = s.braceExpansionII(a);
    debug(res);
    return 0;
}
#endif