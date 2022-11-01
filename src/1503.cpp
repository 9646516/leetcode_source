// id:84778678
// runtime:60 ms
// memory:22.4 MB
// title:Last Moment Before All Ants Fall Out of a Plank
// translatedTitle:所有蚂蚁掉下来前的最后一刻
// questionId:1627
// time:2020-07-05 10:34:27

class Solution {
  public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right) {
        int ret = 0;
        for (int i = 0; i < (int)left.size(); i++) {
            ret = max(ret, left[i]);
        }
        for (int i = 0; i < (int)right.size(); i++) {
            ret = max(ret, n - right[i]);
        }
        return ret;
    }
};