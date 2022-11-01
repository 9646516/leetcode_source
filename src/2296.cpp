// id:354415845
// runtime:960 ms
// memory:297 MB
// title:Design a Text Editor
// translatedTitle:设计一个文本编辑器
// questionId:2389
// time:2022-08-24 18:20:33

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
 * @lc app=leetcode.cn id=2296 lang=cpp
 *
 * [2296] 设计一个文本编辑器
 */

class TextEditor {
  public:
    list<char> V;
    list<char>::iterator pos;
    TextEditor() {
        V.push_back('#');
        V.push_back('#');
        pos = V.begin();
    }

    void addText(string text) {
        for (auto i : text) {
            V.insert(next(pos), i);
            pos++;
        }
    }

    int deleteText(int k) {
        int ret = 0;
        for (int i = 0; i < k; i++) {
            if (*pos == '#')
                break;
            ret++;
            auto p = prev(pos);
            V.erase(pos);
            pos = p;
        }
        return ret;
    }

    string cursorLeft(int k) {
        for (int i = 0; i < k; i++) {
            if (*pos == '#')
                break;
            pos--;
        }
        return gao();
    }
    string gao() {
        string ret;
        auto now = pos;
        for (int i = 0; i < 10; i++) {
            if (*now == '#')
                break;
            ret.push_back(*now);
            now--;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    string cursorRight(int k) {
        for (int i = 0; i < k; i++) {
            if (*next(pos) == '#')
                break;
            pos++;
        }
        return gao();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
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