// id:63874456
// runtime:0 ms
// memory:8.1 MB
// title:拿硬币
// translatedTitle:拿硬币
// questionId:1000056
// time:2020-04-18 15:01:05

class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans=0;
        for(auto &i:coins){
            ans+=i/2+i%2;
        }
        return ans;
    }
};