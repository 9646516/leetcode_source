// id:366932864
// runtime:1000 ms
// memory:192.3 MB
// title:Number of Good Paths
// translatedTitle:好路径的数目
// questionId:2505
// time:2022-09-25 11:32:49

/// 9646516

// #include <bits/stdc++.h>
// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <Licenses - GNU Project - Free Software Foundation>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;
const int INF = 0x3F3F3F3F;
const int maxn = 2e5 + 555;
const int MOD = 1e9 + 7;
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
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
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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

template <int N> struct DSU {
    int fa[N], dep[N];
    void init() {
        iota(fa, fa + N, 0);
        fill(dep, dep + N, 1);
    }
    int seek(int x) { return fa[x] == x ? x : fa[x] = seek(fa[x]); }
    bool merge(int a, int b) {
        int f1 = seek(a), f2 = seek(b);
        if (f1 != f2) {
            if (dep[f1] < dep[f2]) {
                fa[f1] = f2;
            } else if (dep[f1] > dep[f2]) {
                fa[f2] = f1;
            } else {
                fa[f1] = f2;
                dep[f2]++;
            }
            return true;
        } else {
            return false;
        }
    }
    DSU() { init(); }
};

class Solution {
  public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
        vector<int> G[100000 + 555];
        unordered_set<int> V[100000 + 555];
        DSU<50005> dsu;
        for (auto &i : edges) {
            int a = i[0];
            int b = i[1];
            if (vals[a] < vals[b])
                swap(a, b);
            V[a].insert(b);
        }
        vector<int> H;
        for (int i = 0; i < (int)vals.size(); i++) {
            G[vals[i]].push_back(i);
            H.push_back(vals[i]);
        }
        sort(H.begin(), H.end());
        H.erase(unique(H.begin(), H.end()), H.end());
        vector<int> remove;
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i : H) {
            debug(i, G[i]);
            for (int u : G[i]) {
                remove.clear();
                for (int v : V[u]) {
                    if (vals[v] <= i) {
                        remove.push_back(v);
                        dsu.merge(u, v);
                        debug("add", u, v);
                    }
                }
                debug(u, remove);
                for (int v : remove) {
                    V[u].erase(v);
                    // V[v].erase(u);
                }
            }
            cnt.clear();
            for (int u : G[i]) {
                cnt[dsu.seek(u)]++;
            }
            debug(cnt);
            for (auto [a, b] : cnt) {
                ans += 1LL * b * (b - 1) / 2;
            }
        }
        return ans + vals.size();
    }
};
#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{2, 5, 5, 4, 2, 2, 1};
    vector<vector<int>> a{{1, 0}, {2, 0}, {0, 3}, {0, 4}, {5, 2}, {2, 6}};
    Solution s;
    auto res = s.numberOfGoodPaths(data, a);
    debug(res);
    return 0;
}
#endif