// id:78731525
// runtime:540 ms
// memory:84 MB
// title:Find Two Non-overlapping Sub-arrays Each With Target Sum
// translatedTitle:找两个和为目标值且不重叠的子数组
// questionId:1573
// time:2020-06-13 23:58:13

class Solution {
  public:
    int minSumOfLengths(vector<int> &arr, int target) {
        static const int INF = 1e9;
        deque<int> Q;
        deque<int> prefix(arr.size());
        deque<int> suffix(arr.size());
        long long sum = 0;
        int minn = INF;
        for (int j = 0; j < (int)arr.size(); j++) {
            auto i = arr[j];
            Q.push_back(i);
            sum += i;
            while (!Q.empty() && sum > target) {
                sum -= Q.front();
                Q.pop_front();
            }
            if (sum == target) {
                minn = min(minn, (int)Q.size());
            }
            prefix[j] = minn;
        }

        minn = INF;
        sum = 0;
        Q.clear();
        for (int j = (int)arr.size() - 1; j >= 0; j--) {
            auto i = arr[j];
            Q.push_back(i);
            sum += i;
            while (!Q.empty() && sum > target) {
                sum -= Q.front();
                Q.pop_front();
            }
            if (sum == target) {
                minn = min(minn, (int)Q.size());
            }
            suffix[j] = minn;
        }
        int ans = INF;
        for (int i = 0; i + 1 < (int)arr.size(); i++) {
            if (prefix[i] != INF and suffix[i] != INF) {
                ans = min(ans, prefix[i] + suffix[i + 1]);
            }
        }
        return ans == INF ? -1 : ans;
    }
};
