// id:377093816
// runtime:632 ms
// memory:85.9 MB
// title:数字游戏
// translatedTitle:数字游戏
// questionId:1000131
// time:2022-10-27 22:19:44

using ll = long long;
using T = ll;
const int MOD = 1e9 + 7;
constexpr int N = 1 << (__lg(100000) + 1);
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
template <int SZ> struct Seg {
    T seg[2 * SZ];
    static const T ID = 0;
    void init() { F0R(i, 2 * SZ) seg[i] = ID; }
    Seg() { init(); }
    void build() { F0Rd(i, SZ) seg[i] = comb(seg[2 * i], seg[2 * i + 1]); }
    T comb(const T &a, const T &b) const { return a + b; }
    void upd(int p, T value) {
        for (seg[p += SZ] += value; p > 1; p >>= 1)
            seg[p >> 1] = comb(seg[(p | 1) ^ 1], seg[p | 1]);
    }
    void set(const vector<T> &x) {
        assert((int)x.size() <= SZ);
        for (int i = 0; i < (int)x.size(); i++) {
            seg[i + SZ] = x[i];
        }
        build();
    }
    T query(int l, int r) {
        if (l > r)
            return 0;
        T res1 = ID, res2 = ID;
        r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res1 = comb(res1, seg[l++]);
            if (r & 1)
                res2 = comb(seg[--r], res2);
        }
        return comb(res1, res2);
    }
};
Seg<N> seg;
Seg<N> seg2;
struct Treap {
    static const int P = 1e9 + 7;
    struct Node {
        Node *son[2];
        int key, v, cnt, size;
        Node(int v) : key(rand() % P), v(v), cnt(1), size(1) { son[0] = son[1] = null; }
        Node(void *) : key(P), cnt(0), size(0) { son[0] = son[1] = 0; }
        int MinID() { return son[0]->key > son[1]->key; }
        void Up() { size = son[0]->size + cnt + son[1]->size; }
    } * root;
    static Node *null;
    Treap() : root(null) {}
    static void Trans(Node *&pos, int d) {
        Node *s = pos->son[d];
        pos->son[d] = s->son[!d];
        s->son[!d] = pos;
        pos->Up(), s->Up();
        pos = s;
    }
    static int Adjust(Node *&pos) {
        int d = pos->MinID();
        if (pos->key > pos->son[d]->key) {
            Trans(pos, d);
            return !d;
        } else
            return -1;
    }
    static void Insert(Node *&pos, int v) {
        if (pos == null)
            pos = new Node(v);
        else if (pos->v == v) {
            pos->cnt++;
            pos->Up();
        } else {
            Insert(pos->son[pos->v < v], v);
            pos->Up();
            Adjust(pos);
        }
    }
    static void Remove(Node *&pos) {
        if (pos->son[0] == null && pos->son[1] == null)
            pos = null;
        else {
            int p = Adjust(pos);
            Remove(pos->son[p]);
            pos->Up();
        }
    }
    static void Delete(Node *&pos, int v) {
        if (pos->v == v) {
            if (--pos->cnt == 0) {
                pos->key = P;
                Remove(pos);
            } else
                pos->Up();
        } else {
            Delete(pos->son[pos->v < v], v);
            pos->Up();
        }
    }
    void Insert(int x) { Insert(root, x); }
    void Delete(int x) { Delete(root, x); }
    // number of nodes < v
    int Rank(ll v) {
        int res = 0;
        for (Node *pos = root; pos != null;)
            if (pos->v < v) {
                res += pos->cnt + pos->son[0]->size;
                pos = pos->son[1];
            } else
                pos = pos->son[0];
        return res;
    }
    // 1 based
    int Kth(int k) {
        for (Node *pos = root; pos != null;)
            if (pos->son[0]->size + 1 <= k && k <= pos->son[0]->size + pos->cnt)
                return pos->v;
            else if (k <= pos->son[0]->size)
                pos = pos->son[0];
            else {
                k -= pos->son[0]->size + pos->cnt;
                pos = pos->son[1];
            }
        throw;
    }
    int Pred(int v) {
        int res;
        for (Node *pos = root; pos != null;) {
            if (pos->v < v) {
                res = pos->v;
                pos = pos->son[1];
            } else
                pos = pos->son[0];
        }
        return res;
    }
    int Succ(int v) {
        int res;
        for (Node *pos = root; pos != null;) {
            if (pos->v > v) {
                res = pos->v;
                pos = pos->son[0];
            } else
                pos = pos->son[1];
        }
        return res;
    }
};
Treap::Node *Treap::null = new Treap::Node((void *)0);
class Solution {
  public:
    vector<int> numsGame(vector<int> &nums) {
        seg.init();
        seg2.init();
        const int N = nums.size();
        for (int i = 0; i < N; i++)
            nums[i] -= i;
        vector<int> H = nums;
        sort(H.begin(), H.end());
        H.erase(unique(H.begin(), H.end()), H.end());
        // cout << H.size() << endl;
        auto calc = [&](int idx) -> ll {
            idx = lower_bound(H.begin(), H.end(), idx) - H.begin();
            ll L = seg.query(0, idx - 1);
            ll R = seg.query(idx + 1, H.size() - 1);
            ll l_num = seg2.query(0, idx - 1);
            ll r_num = seg2.query(idx + 1, H.size() - 1);

            ll a = l_num * H[idx] - L;
            ll b = R - r_num * H[idx];
            return a + b;
        };
        vector<int> ans;
        Treap st;
        for (int i = 0; i < N; i++) {
            int idx = lower_bound(H.begin(), H.end(), nums[i]) - H.begin();
            seg.upd(idx, nums[i]);
            seg2.upd(idx, 1);
            st.Insert(nums[i]);
            if (i % 2 == 0) {
                int rnk = (i + 2) / 2;
                int mid = st.Kth(rnk);
                auto val = calc(mid);
                ans.push_back(val % MOD);
            } else {
                int l = (i + 1) / 2;
                int r = l + 1;
                int lmid = st.Kth(l);
                int rmid = st.Kth(r);
                auto val = min(calc(lmid), calc(rmid));
                ans.push_back(val % MOD);
            }
        }
        return ans;
    }
};