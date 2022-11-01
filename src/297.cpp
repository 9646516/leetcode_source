// id:313414723
// runtime:36 ms
// memory:30.3 MB
// title:Serialize and Deserialize Binary Tree
// translatedTitle:二叉树的序列化与反序列化
// questionId:297
// time:2022-05-14 18:07:58

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
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#ifdef RINNE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif
class Codec {
  public:
    // Encodes a tree to a single string.
    void dfs(TreeNode *x, stringstream &ss) {
        if (x) {
            ss << x->val << ' ';
            dfs(x->left, ss);
            dfs(x->right, ss);
        } else {
            ss << '#' << ' ';
        }
    }
    string serialize(TreeNode *root) {
        stringstream ss;
        dfs(root, ss);
        return ss.str();
    }
    TreeNode *dfs2(stringstream &ss) {
        string cur;
        ss >> cur;
        if (cur == "#") {
            return nullptr;
        } else {
            TreeNode *now = new TreeNode(stoll(cur));
            now->left = dfs2(ss);
            now->right = dfs2(ss);
            return now;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        stringstream ss(data);
        return dfs2(ss);
    }
};
// class Codec {
//   public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode *root) {
//         stringstream ss;
//         queue<TreeNode *> q1, q2;
//         q1.push(root);
//         while (!q1.empty()) {
//             while (!q1.empty()) {
//                 auto now = q1.front();
//                 q1.pop();
//                 if (now == nullptr)
//                     ss << "null" << ',';
//                 else {
//                     ss << now->val << ',';
//                     q2.push(now->left);
//                     q2.push(now->right);
//                 }
//             }
//             swap(q1, q2);
//         }
//         return ss.str();
//     }

//     // Decodes your encoded data to tree.
//     TreeNode *deserialize(string data) {
//         deque<optional<int>> V;
//         string now;
//         for (int i = 0; i < (int)data.size(); i++) {
//             if (data[i] == ',') {
//                 if (now == "null")
//                     V.push_back(nullopt);
//                 else {
//                     V.push_back(stol(now));
//                 }
//                 now.clear();
//             } else {
//                 now.push_back(data[i]);
//             }
//         }
//         if (!V.front().has_value())
//             return nullptr;
//         queue<TreeNode *> q1, q2;
//         TreeNode *root = new TreeNode(V.front().value());
//         V.pop_front();
//         q1.push(root);
//         while (!q1.empty()) {
//             while (!q1.empty()) {
//                 auto now = q1.front();
//                 q1.pop();
//                 if (now == nullptr) {
//                     continue;
//                 } else {
//                     TreeNode *l = nullptr;
//                     if (!V.empty()) {
//                         if (V.front().has_value())
//                             l = new TreeNode(V.front().value());
//                         V.pop_front();
//                     }

//                     TreeNode *r = nullptr;
//                     if (!V.empty()) {
//                         if (V.front().has_value())
//                             r = new TreeNode(V.front().value());
//                         V.pop_front();
//                     }
//                     now->left = l;
//                     now->right = r;
//                     if (l)
//                         q2.push(l);
//                     if (r)
//                         q2.push(r);
//                 }
//             }
//             swap(q1, q2);
//         }
//         return root;
//     }
// };

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

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