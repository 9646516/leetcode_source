// id:373342182
// runtime:4 ms
// memory:5.8 MB
// title:Number of Valid Clock Times
// translatedTitle:有效时间的数目
// questionId:2528
// time:2022-10-15 22:54:48

class Solution {
  public:
    bool solve(int a, int b, int c, int d) {
        if (a > 2)
            return 0;
        if (a == 2) {
            if (b > 3)
                return 0;
        }
        if (c >= 6)
            return 0;
        return 1;
    }
    int countTime(string time) {
        int ans = 0;
        for (int a = 0; a <= 9; a++)
            for (int b = 0; b <= 9; b++)
                for (int c = 0; c <= 9; c++)
                    for (int d = 0; d <= 9; d++) {
                        if (time[0] != '?' && time[0] - '0' != a)
                            continue;
                        if (time[1] != '?' && time[1] - '0' != b)
                            continue;
                        if (time[3] != '?' && time[3] - '0' != c)
                            continue;
                        if (time[4] != '?' && time[4] - '0' != d)
                            continue;
                        ans += solve(a, b, c, d);
                    }
        return ans;
    }
};