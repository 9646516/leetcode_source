// id:378193194
// runtime:1388 ms
// memory:267.9 MB
// title:Online Majority Element In Subarray
// translatedTitle:子数组中占绝大多数的元素
// questionId:1262
// time:2022-10-31 22:40:17

const int maxn = 2e4 + 5;

int s[150][maxn];
int p[150][150];
int l[150], r[150], id[maxn];
class MajorityChecker {
  public:
    vector<int> V;
    int get(int l, int r, int val) {
        int ret = s[r][val];
        if (l)
            ret -= s[l - 1][val];
        return ret;
    }
    MajorityChecker(vector<int> &arr) {
        int block_size = sqrt(arr.size());
        V = arr;
        for (int i = 0; i < arr.size(); i++) {
            id[i] = i / block_size;
        }
        memset(s, 0, sizeof(s));
        for (int i = 0; i <= id[arr.size() - 1]; i++) {
            l[i] = i * block_size;
            r[i] = (i + 1) * block_size - 1;
            if (r[i] >= arr.size())
                r[i] = arr.size() - 1;
        }
        for (int i = 0; i < arr.size(); i++) {
            s[id[i]][arr[i]]++;
        }
        for (int i = 1; i <= id[arr.size() - 1]; i++) {
            for (int j = 0; j < maxn; j++) {
                s[i][j] += s[i - 1][j];
            }
        }
        memset(p, -1, sizeof(p));
        for (int i = 0; i <= id[arr.size() - 1]; i++) {
            for (int j = i; j <= id[arr.size() - 1]; j++) {
                if (i != j) {
                    p[i][j] = p[i][j - 1];
                }
                int best;
                for (int k = l[j]; k <= r[j]; k++) {
                    int now = get(i, j, arr[k]);
                    if (p[i][j] == -1 || now > best) {
                        p[i][j] = arr[k];
                        best = now;
                    }
                }
            }
        }
    }
    int query(int left, int right, int threshold) {
        int ans;
        int best;
        unordered_map<int, int> cnt;
        if (id[left] + 1 < id[right]) {
            for (int i = left; i <= r[id[left]]; i++) {
                cnt[V[i]]++;
            }
            for (int i = l[id[right]]; i <= right; i++) {
                cnt[V[i]]++;
            }
            int L = id[left] + 1, R = id[right] - 1;
            ans = p[L][R];
            best = get(L, R, ans) + cnt[ans];
            for (int i = left; i <= r[id[left]]; i++) {
                int now = get(L, R, V[i]) + cnt[V[i]];
                if (now > best) {
                    ans = V[i];
                    best = now;
                }
            }
            for (int i = l[id[right]]; i <= right; i++) {
                int now = get(L, R, V[i]) + cnt[V[i]];
                if (now > best) {
                    ans = V[i];
                    best = now;
                }
            }
        } else {
            ans = -1;
            for (int i = left; i <= right; i++) {
                cnt[V[i]]++;
            }
            for (int i = left; i <= right; i++) {
                int now = cnt[V[i]];
                if (ans == -1 || now > best) {
                    ans = V[i];
                    best = now;
                }
            }
        }
        if (ans == -1 || best < threshold)
            ans = -1;
        return ans;
    }
};
