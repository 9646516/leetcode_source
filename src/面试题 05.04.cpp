// id:374577775
// runtime:0 ms
// memory:6 MB
// title:Closed Number LCCI
// translatedTitle:下一个数
// questionId:100183
// time:2022-10-19 18:59:16


class Solution {
  public:
    using ll = long long;

    int get_next(vector<int> B) {
        int f0 = -1, f1 = -1;
        for (int i = 0; i < B.size(); i++) {
            if (B[i] == 1) {
                f1 = i;
                break;
            }
        }
        if (f1 == -1)
            return -1;
        for (int i = f1 + 1; i < B.size(); i++) {
            if (B[i] == 0) {
                f0 = i;
                break;
            }
        }
        if (f0 == -1)
            return -1;
        for (int i = f0 - 1; i >= 0; i--) {
            if (B[i] == 1) {
                f1 = i;
                break;
            }
        }
        swap(B[f0], B[f1]);
        int cnt = 0;
        for (int i = f1 - 1; i >= 0; i--) {
            if (B[i]) {
                B[i] = 0;
                cnt++;
            }
        }
        for (int i = 0; i < cnt; i++) {
            B[i] = 1;
        }
        ll ret = 0;
        for (int i = 0; i < B.size(); i++)
            ret += (1LL * B[i]) << i;
        if (ret > numeric_limits<int>::max())
            ret = -1;
        return ret;
    }
    int get_prev(vector<int> B) {
        int f0 = -1, f1 = -1;
        for (int i = 0; i < B.size(); i++) {
            if (B[i] == 0) {
                f0 = i;
                break;
            }
        }
        if (f0 == -1)
            return -1;
        for (int i = f0 + 1; i < B.size(); i++) {
            if (B[i] == 1) {
                f1 = i;
                break;
            }
        }
        if (f1 == -1)
            return -1;
        for (int i = f1 - 1; i >= 0; i--) {
            if (B[i] == 0) {
                f0 = i;
                break;
            }
        }
        swap(B[f0], B[f1]);
        int cnt = 0;
        for (int i = f0 - 1; i >= 0; i--) {
            if (B[i] == 0) {
                B[i] = 1;
                cnt++;
            }
        }
        for (int i = 0; i < cnt; i++) {
            B[i] = 0;
        }
        ll ret = 0;
        for (int i = 0; i < B.size(); i++)
            ret += (1LL * B[i]) << i;
        if (ret > numeric_limits<int>::max())
            ret = -1;
        return ret;
    }

    vector<int> findClosedNumbers(int num) {
        vector<int> B;
        for (int i = 0; i <= 31; i++)
            B.push_back((num >> i) & 1);
        B.push_back(0);
        return {get_next(B), get_prev(B)};
    }
};