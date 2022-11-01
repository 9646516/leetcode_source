// id:361531244
// runtime:12 ms
// memory:10 MB
// title:Optimal Partition of String
// translatedTitle:子字符串的最优划分
// questionId:2487
// time:2022-09-11 10:49:11

class Solution {
  public:
    int partitionString(string s) {
        int ans = 0;
        int mask = 0;
        for (char i : s) {
            int B=i-'a';
            if(((mask>>B)&1)){
                ans++;
                mask=1<<B;
            }else{
                mask|=1<<B;
            }
        }
        if(mask)ans++;
        return ans;
    }
};