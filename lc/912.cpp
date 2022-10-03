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
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
struct Heap {
    Heap() {}
    Heap(vector<int> &G) : V(G) { make(); }
    Heap(vector<int> &&G) : V(G) { make(); }
    decltype(auto) size() const { return V.size(); }
    void push(int val) {
        V.push_back(val);
        push_up((int)V.size() - 1);
    };
    int pop() {
        int val = V[0];
        V[0] = V.back();
        V.pop_back();
        if (!V.empty()) {
            push_down(0);
        }
        return val;
    };

  private:
    vector<int> V;
    void make() {
        for (int i = (int)V.size() / 2; i >= 0; i--) {
            push_down(i);
        }
    };

    void push_up(int idx) {
        while (idx != 0) {
            int fa = idx / 2;
            int s1 = fa * 2, s2 = fa * 2 + 1;
            int mn = fa;
            if (s1 < V.size() && V[mn] > V[s1]) {
                mn = s1;
            }
            if (s2 < V.size() && V[mn] > V[s2]) {
                mn = s2;
            }
            if (mn != fa) {
                swap(V[fa], V[mn]);
                idx = fa;
            } else {
                break;
            }
        }
    }
    void push_down(int idx) {
        int s1 = idx * 2, s2 = idx * 2 + 1;
        int mn = idx;
        if (s1 < V.size() && V[mn] > V[s1]) {
            mn = s1;
        }
        if (s2 < V.size() && V[mn] > V[s2]) {
            mn = s2;
        }
        if (idx != mn) {
            swap(V[idx], V[mn]);
            push_down(mn);
        }
    }
};

class Solution {
  public:
    void merge_sort(vector<int> &V, int l, int r) {
        if (l < r) {
            static vector<int> G;
            G.clear();
            int mid = (l + r) / 2;
            merge_sort(V, l, mid);
            merge_sort(V, mid + 1, r);
            int p1 = l, p2 = mid + 1;
            while (p1 <= mid && p2 <= r) {
                if (V[p1] < V[p2]) {
                    G.push_back(V[p1]);
                    p1++;
                } else {
                    G.push_back(V[p2]);
                    p2++;
                }
            }
            while (p1 <= mid) {
                G.push_back(V[p1]);
                p1++;
            }
            while (p2 <= r) {
                G.push_back(V[p2]);
                p2++;
            }
            for (int i = 0; i < G.size(); i++) {
                V[l + i] = G[i];
            }
        }
    }
    void quick_sort(vector<int> &V, int l, int r) {
        if (l < r) {
            int val = rand() % (r - l + 1) + l;
            swap(V[val], V[r]);
            int pos = l;
            for (int i = l; i < r; i++) {
                if (V[i] <= V[r]) {
                    swap(V[i], V[pos]);
                    pos++;
                }
            }
            swap(V[pos], V[r]);
            int pos2 = pos - 1;
            while (pos2 >= l && V[pos2] == V[pos]) {
                pos2--;
            }
            quick_sort(V, l, pos2);
            quick_sort(V, pos + 1, r);
        }
    }
    void heap_sort(vector<int> &V) {
#if 1
        Heap heap(V);
#else
        Heap heap;
        for (int i : V)
            heap.push(i);
#endif
        vector<int> ret;
        while (heap.size() > 0) {
            ret.push_back(heap.pop());
        }
        V = move(ret);
    }
    void radix_sort(vector<int> &V) {
        vector<int> V2(V.size());
        int P = 1;
        int mx = *max_element(V.begin(), V.end());
        while (P <= mx) {
            vector<int> cnt(100);
            for (int i : V) {
                cnt[(i / P) % 100]++;
            }
            for (int i = 1; i < 100; i++)
                cnt[i] += cnt[i - 1];
            for (int i = (int)V.size() - 1; i >= 0; i--) {
                int idx = cnt[(V[i] / P) % 100]++;
                int pos = cnt[idx] - 1;
                V2[pos] = V[i];
                cnt[idx]--;
            }
            swap(V, V2);
        }
    }
    vector<int> sortArray(vector<int> &V) {
        heap_sort(V);
        return V;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{5, 2, 3, 1};
    Solution s;
    auto res = s.sortArray(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
