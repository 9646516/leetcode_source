// id:82506264
// runtime:4 ms
// memory:7.3 MB
// title:Average Salary Excluding the Minimum and Maximum Salary
// translatedTitle:去掉最低工资和最高工资后的工资平均值
// questionId:1584
// time:2020-06-27 22:31:40

using ll = long long;
class Solution {
  public:
    double average(vector<int> &salary) {
        sort(salary.begin(), salary.end());
        ll sum = accumulate(salary.begin(), salary.end(), 0LL);
        sum -= salary.front() + salary.back();
        return 1.0 * sum / (salary.size() - 2);
    }
};