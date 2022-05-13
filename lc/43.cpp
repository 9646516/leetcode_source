// @lc code=start
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
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
struct Int {
    vector<int> sb;
    Int() = default;
    Int(const string &s) {
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            sb.push_back(s[i] - '0');
        }
    }
    Int mul(int val) const {
        Int ret;
        ret.sb.assign(this->sb.begin(), this->sb.end());
        for (auto &i : ret.sb) {
            i *= val;
        }
        int lbit = 0;
        for (int i = 0; i < (int)ret.sb.size(); i++) {
            ret.sb[i] += lbit;
            lbit = ret.sb[i] / 10;
            ret.sb[i] %= 10;
        }
        ret.sb.push_back(lbit);
        while (ret.sb.size() > 1 && ret.sb.back() == 0) {
            ret.sb.pop_back();
        }

        return ret;
    }
    void mul10(int times) {
        reverse(sb.begin(), sb.end());
        while (times--) {
            sb.push_back(0);
        }
        reverse(sb.begin(), sb.end());
    }
    friend Int operator+(const Int &a, const Int &b) {
        int len = max(a.size(), b.size());
        Int sum;
        int lbit = 0;
        for (int i = 0; i < len; i++) {
            int val = (i < a.size() ? a.sb[i] : 0) + (i < b.size() ? b.sb[i] : 0) + lbit;
            if (val >= 10) {
                sum.sb.push_back(val - 10);
                lbit = 1;
            } else {
                sum.sb.push_back(val);
                lbit = 0;
            }
        }
        if (lbit) {
            sum.sb.push_back(1);
        }
        return sum;
    }

    friend Int operator*(const Int &_a, const Int &_b) {
        const Int *a, *b;
        if (_a.size() < _b.size()) {
            a = &_a;
            b = &_b;
        } else {
            b = &_a;
            a = &_b;
        }
        Int sum;
        for (int i = 0; i < (int)a->sb.size(); i++) {
            Int res = b->mul(a->sb[i]);
            res.mul10(i);
            sum = sum + res;
        }
        return sum;
    }
    int size() const { return (int)sb.size(); }
    string to_string() const {
        string ss;
        for (int i = (int)sb.size() - 1; i >= 0; i--) {
            ss.push_back(sb[i] + '0');
        }
        return ss;
    }
};

class Solution {
  public:
    string multiply(string num1, string num2) {
        Int a(num1);
        Int b(num2);
        Int res = a * b;
        return res.to_string();
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
    const char *a = "123456789", *b = "987";
    auto res = s.multiply(a, b);
    debug(atoll(a) * atoll(b));
    debug(res);
    return 0;
}
#endif
// @lc code=end
