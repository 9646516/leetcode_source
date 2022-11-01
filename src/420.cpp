// id:313012457
// runtime:0 ms
// memory:6.1 MB
// title:Strong Password Checker
// translatedTitle:强密码检验器
// questionId:420
// time:2022-05-13 16:11:06

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
 * @lc app=leetcode.cn id=420 lang=cpp
 *
 * [420] 强密码检验器
 */
class Solution {
  public:
    int get_bit(char s) {
        if (s >= 'a' && s < 'z')
            return 1;
        else if (s >= 'A' && s < 'Z')
            return 2;
        else if (s >= '0' && s < '9')
            return 4;
        else
            return 0;
    }
    int strongPasswordChecker(string ss) {
        int mask = 0;
        for (int i = 0; i < (int)ss.size(); i++)
            mask |= get_bit(ss[i]);
        int need_chr = 3 - __builtin_popcount(mask);
        if (ss.size() < 6) {
            int padding = 6 - ss.size();
            return max(padding, need_chr);
        } else {
            vector<int> V;
            {
                int last = 114514;
                int len = 0;
                for (int i = 0; i < (int)ss.size(); i++) {
                    if (ss[i] == last) {
                        len++;
                    } else {
                        V.push_back(len);
                        last = ss[i];
                        len = 1;
                    }
                }
                V.push_back(len);
            }
            debug(V);
            int need_replace = 0;
            for (int i : V)
                need_replace += i / 3;
            if (ss.size() <= 20) {
                return max(need_replace, need_chr);
            } else {
                map<int, vector<int>> cnt;
                for (int i : V)
                    if (i >= 3)
                        cnt[i % 3].push_back(i);
                debug(cnt);
                int need_remove = ss.size() - 20;
                int reducer = need_remove;
                debug(need_remove);
                for (int i = 0; i < 2; i++) {
                    int cost = i + 1;
                    auto &v = cnt[i];
                    for (auto val : v) {
                        if (reducer < cost)
                            break;
                        cnt[2].push_back(val - cost);
                        reducer -= cost;
                        need_replace--;
                    }
                }
                {
                    auto &v = cnt[2];
                    for (auto val : v) {
                        int has = min(val / 3, reducer / 3);
                        reducer -= has * 3;
                        need_replace -= has;
                    }
                }
                debug(reducer, need_replace, need_chr);
                return need_remove + max(need_replace, need_chr);
            }
        }
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
    auto res = s.strongPasswordChecker("FFFFFFFFFFFFFFF11111111111111111111AAA");
    debug(res);
    return 0;
}
#endif