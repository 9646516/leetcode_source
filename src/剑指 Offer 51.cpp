// id:373624970
// runtime:160 ms
// memory:42.3 MB
// title:数组中的逆序对  LCOF
// translatedTitle:数组中的逆序对
// questionId:100318
// time:2022-10-16 21:15:07

class Solution {
  public:
    int ans;
    void solve(vector<int> &V, int l, int r) {
        if (l >= r)
            return;
        else if (l + 1 == r) {
            if (V[l] > V[r]) {
                ans++;
                swap(V[l], V[r]);
            }
        } else {
            int mid = (l + r) / 2;
            solve(V, l, mid);
            solve(V, mid + 1, r);
            static vector<int> G;
            G.clear();
            int p1 = l, p2 = mid + 1;
            while (p1 <= mid && p2 <= r) {
                if (V[p1] <= V[p2]) {
                    G.push_back(V[p1]);
                    p1++;
                } else {
                    G.push_back(V[p2]);
                    p2++;
                    ans += mid - p1 + 1;
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
    int reversePairs(vector<int> &nums) {
        ans = 0;
        solve(nums, 0, nums.size() - 1);
        return ans;
    }
};