// id:374204941
// runtime:0 ms
// memory:6.4 MB
// title:复原 IP 
// translatedTitle:复原 IP 
// questionId:1000241
// time:2022-10-18 16:47:05

class Solution {
  public:
    bool check(string &x) {
        if(x.size() ==0||x.size() > 3)return 0;
        if (x.size() > 1 && x[0] == '0')
            return 0;
        int val = stol(x);
        return val <= 255;
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 3 * 4)
            return {};
        const int N = s.size();
        vector<string> ans;
        for (int a = 0; a < N; a++) {
            string s1 = s.substr(0, a - 0 + 1);
            if (!check(s1))
                continue;
            for (int b = a + 1; b < N; b++) {
                string s2 = s.substr(a + 1, b - (a + 1) + 1);
                if (!check(s2))
                    continue;
                for (int c = b + 1; c < N; c++) {
                    string s3 = s.substr(b + 1, c - (b + 1) + 1);
                    if (!check(s3))
                        continue;
                    string s4 = s.substr(c + 1);
                    if (!check(s4))
                        continue;
                    stringstream ss;
                    ss << s1 << '.' << s2 << '.' << s3 << '.' << s4;
                    ans.push_back(ss.str());
                }
            }
        }
        return ans;
    }
};