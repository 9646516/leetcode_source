// id:374893450
// runtime:32 ms
// memory:9.6 MB
// title:Basic Calculator
// translatedTitle:基本计算器
// questionId:224
// time:2022-10-20 17:59:41


class Solution {
  public:
    int calculate(string s) {
        deque<char> op;
        deque<int> val;
        int now = 0;
        int vis = 0;
        string s2;
        for (char i : s) {
            if (i == ' ')
                continue;
            else if (i == '-') {
                if (s2.empty() ||  s2.back() == '(') {
                    s2.push_back('0');
                }
                s2.push_back(i);
            } else {
                s2.push_back(i);
            }
        }
        for (char i : s2) {
            if (isdigit(i)) {
                vis = 1;
                now = now * 10 - '0' + i;
            } else {
                if (vis) {
                    val.push_back(now);
                    now = 0;
                    vis = 0;
                }
                if (i == '+' || i == '-') {
                    while (!op.empty() && (op.back() == '+' || op.back() == '-')) {
                        int b = val.back();
                        val.pop_back();
                        int a = val.back();
                        val.pop_back();
                        char opt = op.back();
                        op.pop_back();
                        if (opt == '+') {
                            val.push_back(a + b);
                        }
                        if (opt == '-') {
                            val.push_back(a - b);
                        }
                    }
                    op.push_back(i);
                } else if (i == '(') {
                    op.push_back(i);
                } else {
                    while (!op.empty() && op.back() != '(') {
                        int b = val.back();
                        val.pop_back();
                        int a = val.back();
                        val.pop_back();
                        char opt = op.back();
                        op.pop_back();
                        if (opt == '+') {
                            val.push_back(a + b);
                        }
                        if (opt == '-') {
                            val.push_back(a - b);
                        }
                    }
                    op.pop_back();
                }
            }
        }
        if (vis)
            val.push_back(now);
        while (!op.empty()) {
            int b = val.back();
            val.pop_back();
            int a = val.back();
            val.pop_back();
            char opt = op.back();
            op.pop_back();
            if (opt == '+') {
                val.push_back(a + b);
            }
            if (opt == '-') {
                val.push_back(a - b);
            }
        }
        return val.back();
    }
};