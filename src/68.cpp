// id:298023176
// runtime:0 ms
// memory:7.3 MB
// title:Text Justification
// translatedTitle:文本左右对齐
// questionId:68
// time:2022-04-10 22:29:24

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
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

class Solution {
  public:
    vector<string> fullJustify(vector<string> &S, int len) {
        vector<vector<string>> V;
        int left = len;
        bool empty = true;
        vector<string> now;
        for (auto &i : S) {
            int consume = i.size();
            if (!empty)
                consume++;
            if (left - consume < 0) {
                V.push_back(now);
                now.clear();
                now.push_back(i);
                left = len - (int)i.size();
            } else {
                now.push_back(i);
                left -= consume;
            }
            empty = false;
        }
        if (!now.empty())
            V.push_back(now);
        vector<string> ret;
        for (int _i = 0; _i < (int)V.size(); _i++) {
            auto &i = V[_i];
            if (_i != (int)V.size() - 1) {
                int tot = 0;
                for (auto &j : i) {
                    tot += j.size();
                }
                int blank = len - tot;
                int spliter = (int)i.size() - 1;
                if (spliter == 0) {
                    ret.push_back(i[0]);
                    while (ret.back().size() < len) {
                        ret.back().push_back(' ');
                    }
                } else {
                    int avg = blank / spliter;
                    int promote = blank - avg * spliter;
                    stringstream ss;
                    for (int j = 0; j < (int)i.size(); j++) {
                        ss << i[j];
                        if (j != (int)i.size() - 1) {
                            for (int k = 0; k < avg; k++) {
                                ss << ' ';
                            }
                        }
                        if (promote) {
                            promote--;
                            ss << ' ';
                        }
                    }
                    ret.push_back(ss.str());
                }
            } else {
                stringstream ss;
                for (auto &j : i) {
                    ss << j << ' ';
                }
                ret.push_back(ss.str());
                ret.back().pop_back();
                while (ret.back().size() < len) {
                    ret.back().push_back(' ');
                }
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