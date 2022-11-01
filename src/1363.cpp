// id:366037654
// runtime:8 ms
// memory:20.4 MB
// title:Largest Multiple of Three
// translatedTitle:形成三的最大倍数
// questionId:1277
// time:2022-09-22 18:31:32

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
 * @lc app=leetcode.cn id=1363 lang=cpp
 *
 * [1363] 形成三的最大倍数
 */

class Solution {
  public:
    string largestMultipleOfThree(vector<int> &digits) {
        int xs = 0;
        vector<int> V[3];
        sort(digits.begin(), digits.end());
        for (int i : digits) {
            xs += i % 3;
            V[i % 3].push_back(i);
        }
        xs %= 3;
        string sb;
        for (auto i : digits) {
            sb.push_back(i + '0');
        }
        if (xs == 0) {

        } else if (xs == 1) {
            if (V[1].size() >= 1) {
                sb.erase(sb.find(V[1][0] + '0'), 1);
            } else if (V[2].size() >= 2) {
                sb.erase(sb.find(V[2][0] + '0'), 1);
                sb.erase(sb.find(V[2][1] + '0'), 1);
            } else {
                return "";
            }
        } else if (xs == 2) {
            if (V[2].size() >= 1) {
                sb.erase(sb.find(V[2][0] + '0'), 1);
            } else if (V[1].size() >= 2) {
                sb.erase(sb.find(V[1][0] + '0'), 1);
                sb.erase(sb.find(V[1][1] + '0'), 1);
            } else {
                return "";
            }
        }
        if (sb.empty()) {
            return "";
        }
        while (!sb.empty() && sb.back() == '0') {
            sb.pop_back();
        }
        if (sb.empty()) {
            sb.push_back('0');
        }
        reverse(sb.begin(), sb.end());
        return sb;
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