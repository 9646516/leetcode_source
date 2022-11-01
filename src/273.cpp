// id:301003754
// runtime:0 ms
// memory:7 MB
// title:Integer to English Words
// translatedTitle:整数转换英文表示
// questionId:273
// time:2022-04-16 20:29:48

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
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */
const char *word1[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const char *word2[] = {"",      "",      "Twenty",  "Thirty", "Forty",
                       "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char *word3[] = {"Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                       "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

class Solution {
  public:
    vector<string> V;
    void solve(int x) {
        if (x >= 100) {
            int n = x / 100;
            x %= 100;
            V.push_back(word1[n]);
            V.push_back("Hundred");
        }
        if (x >= 20) {
            int n = x / 10;
            x %= 10;
            V.push_back(word2[n]);
            if (x) {
                V.push_back(word1[x]);
            }
        } else if (x >= 10) {
            V.push_back(word3[x - 10]);
        } else if (x) {
            V.push_back(word1[x]);
        }
    }
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        if (num >= 1'000'000'000) {
            int n = num / 1'000'000'000;
            num %= 1'000'000'000;
            V.push_back(word1[n]);
            V.push_back("Billion");
        }
        if (num >= 1'000'000) {
            int n = num / 1'000'000;
            num %= 1'000'000;
            solve(n);
            V.push_back("Million");
        }
        if (num >= 1'000) {
            int n = num / 1'000;
            num %= 1'000;
            solve(n);
            V.push_back("Thousand");
        }
        solve(num);
        stringstream ss;
        ss << V[0];
        for (int i = 1; i < (int)V.size(); i++)
            ss << ' ' << V[i];
        return ss.str();
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