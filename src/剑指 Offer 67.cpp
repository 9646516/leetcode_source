// id:373655776
// runtime:0 ms
// memory:6.1 MB
// title:把字符串转换成整数 LCOF
// translatedTitle:把字符串转换成整数
// questionId:100340
// time:2022-10-16 22:51:28

class Solution {
  public:
    int strToInt(string str) {
        long long now = 0;
        int pos = 1;
        int s;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ')
                continue;
            else if (str[i] == '+') {
                s = i + 1;
                break;
            } else if (str[i] == '-') {
                s = i + 1;
                pos = 0;
                break;
            } else if (isdigit(str[i])) {
                s = i;
                break;
            } else {
                return 0;
            }
        }
        if (s >= str.size() || !isdigit(str[s]))
            return 0;
        for (int i = s; i < str.size(); i++) {
            if(now>1e10)break;
            if (isdigit(str[i])) {
                now = now * 10 + str[i] - '0';
            } else {
                break;
            }
        }
        if (!pos)
            now = -now;
        now = min(now, 1LL * numeric_limits<int>::max());
        now = max(now, 1LL * numeric_limits<int>::min());
        return now;
    }
};