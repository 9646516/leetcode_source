// id:376412000
// runtime:20 ms
// memory:10.2 MB
// title:集水器
// translatedTitle:集水器
// questionId:1000486
// time:2022-10-25 20:22:31


#define IDX(x, y, z) ((((x)*M + (y)) * 4) + (z))
template <int N> struct DSU {
    int fa[N];
    void init() { iota(fa, fa + N, 0); }
    int seek(int x) { return fa[x] == x ? x : fa[x] = seek(fa[x]); }
    void merge(int a, int b) {
        int f1 = seek(a), f2 = seek(b);
        fa[f1] = f2;
    }
};
DSU<50 * 50 * 4 + 5> dsu;

class Solution {
  public:
    int reservoir(vector<string> &shape) {
        dsu.init();
        const int N = shape.size();
        const int M = shape.front().size();
        int vis[55][55][4];
        memset(vis, 0, sizeof(vis));
        unordered_set<int> st;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                if (i != N - 1) {
                    dsu.merge(IDX(i, j, 3), IDX(i + 1, j, 0));
                }
                if (j != M - 1) {
                    dsu.merge(IDX(i, j, 2), IDX(i, j + 1, 1));
                }
                if (shape[i][j] == '.') {
                    dsu.merge(IDX(i, j, 0), IDX(i, j, 1));
                    dsu.merge(IDX(i, j, 0), IDX(i, j, 2));
                    dsu.merge(IDX(i, j, 0), IDX(i, j, 3));
                } else if (shape[i][j] == 'r') {
                    dsu.merge(IDX(i, j, 0), IDX(i, j, 1));
                    dsu.merge(IDX(i, j, 2), IDX(i, j, 3));
                } else {
                    dsu.merge(IDX(i, j, 0), IDX(i, j, 2));
                    dsu.merge(IDX(i, j, 1), IDX(i, j, 3));
                }
            }
            st.clear();
            for (int j = i; j < N; j++) {
                st.insert(dsu.seek(IDX(j, 0, 1)));
                st.insert(dsu.seek(IDX(j, M - 1, 2)));
            }
            for (int j = 0; j < M; j++) {
                st.insert(dsu.seek(IDX(N - 1, j, 3)));
            }
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < 4; k++) {
                    int f = dsu.seek(IDX(i, j, k));
                    if (!st.count(f)) {
                        vis[i][j][k] = 1;
                    }
                }
            }
        }
        st.clear();
        for (int i = 0; i < M; i++) {
            st.insert(dsu.seek(IDX(0, i, 0)));
            st.insert(dsu.seek(IDX(N - 1, i, 3)));
        }
        for (int i = 0; i < N; i++) {
            st.insert(dsu.seek(IDX(i, 0, 1)));
            st.insert(dsu.seek(IDX(i, M - 1, 2)));
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < 4; k++) {
                    if (vis[i][j][k]) {
                        int f = dsu.seek(IDX(i, j, k));
                        if (st.count(f))
                            ans++;
                    }
                }
            }
        }
        return ans / 2;
    }
};