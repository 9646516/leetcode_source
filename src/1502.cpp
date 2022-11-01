// id:84775975
// runtime:4 ms
// memory:8.9 MB
// title:Can Make Arithmetic Progression From Sequence
// translatedTitle:判断能否形成等差数列
// questionId:1626
// time:2020-07-05 10:31:32

class Solution {
  public:
    bool canMakeArithmeticProgression(vector<int> &ar) {
        sort(ar.begin(), ar.end());
        int dis = ar[1] - ar[0];
        bool ok = true;
        for (int i = 1; i < (int)ar.size(); i++) {
            ok &= ar[i] - ar[i - 1] == dis;
        }
        return ok;
    }
};