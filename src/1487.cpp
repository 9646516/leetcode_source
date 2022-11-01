// id:80716926
// runtime:1068 ms
// memory:62.2 MB
// title:Making File Names Unique
// translatedTitle:保证文件名唯一
// questionId:1611
// time:2020-06-21 10:48:26

class Solution {
  public:
    vector<string> getFolderNames(vector<string> &names) {
        vector<string> ret;
        set<string> mp;
        map<string, int> mp2;
        for (auto &i : names) {
            if (mp.count(i)) {
                int x = mp2[i];
                string s = i;
                while (mp.count(s)) {
                    s = i + "(" + to_string(++x) + ")";
                }
                mp2[i] = x;
                mp.insert(s);
                ret.emplace_back(s);
            } else {
                mp2[i] = 0;
                mp.insert(i);
                ret.emplace_back(i);
            }
        }
        return ret;
    }
};