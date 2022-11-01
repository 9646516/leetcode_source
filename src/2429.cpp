// id:369172077
// runtime:0 ms
// memory:5.7 MB
// title:Minimize XOR
// translatedTitle:最小 XOR
// questionId:2509
// time:2022-10-02 10:41:07

class Solution {
  public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        int ans = 0;
        while (cnt) {
            bool ok = 0;
            for (int i = 31; i >= 0; i--) {
                if (((num1 >> i) & 1) == 1 && ((ans >> i) & 1) == 0) {
                    ans ^= (1 << i);
                    cnt--;
                    ok = 1;
                    break;
                }
            }
            if (!ok) {
                for (int i = 0; i <= 31; i++) {
                    if (((num1 >> i) & 1) == 0 && ((ans >> i) & 1) == 0) {
                        ans ^= (1 << i);
                        cnt--;
                        ok = 1;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};