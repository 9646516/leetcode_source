// id:96076085
// runtime:208 ms
// memory:15.1 MB
// title:Minimum Insertions to Balance a Parentheses String
// translatedTitle:平衡括号字符串的最少插入次数
// questionId:1648
// time:2020-08-08 23:18:25

#include <bits/stdc++.h>
using namespace std;
// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
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
string to_string(char a) { return string(1, a); }
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
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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
using ll = long long;
const int INF = 0x3F3F3F3F;
const int maxn = 2e5 + 555;
const int MOD = 1e9 + 7;
ll xpow(ll a, ll b) {
    ll ret = 1;
    a %= MOD;
    assert(b >= 0);
    while (b) {
        if (b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
class Solution {
  public:
    int minInsertions(string s) {
        deque<char> st;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == '(')
                st.push_back('[');
            else if (s[i] == ')') {
                if (!st.empty() && st.end()[-1] == ')') {
                    st.pop_back();
                    st.push_back(']');
                } else {
                    st.push_back(s[i]);
                }
            }
        }
        deque<char> q;
        int ret = 0;
        for (auto i : st) {
            if (i == '[')
                q.push_back('[');
            else if (i == ']') {
                if (!q.empty() && q.back() == '[')
                    q.pop_back();
                else {
                    q.push_back(']');
                }
            } else {
                if (!q.empty() && q.back() == '[') {
                    q.pop_back();
                    ret++;
                } else {
                    q.push_back(')');
                }
            }
        }
        debug(q);
        for(auto i:q){
            if(i=='[')ret+=2;
            if(i==']')ret+=1;
            if(i==')')ret+=2;
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
    auto a = Solution();
    cout << a.minInsertions("(((()))()())))") << endl;
    return 0;
}
#endif

// "(((()))()())))"
// "()())))()"
// "(((()(()((())))(((()())))()())))(((()(()()((()()))"

// "(((()(()((((()))()))(((()(()()((())"
//  (((()    (()   ((((()))  ()))   (((()  (()  ()   ((())
//  7        3     7
// [[[[)  [[)  [[[[[)  ][)][[[[)[[)[)[[[))