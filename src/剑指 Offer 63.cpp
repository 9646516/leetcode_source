// id:373661078
// runtime:4 ms
// memory:12.6 MB
// title:股票的最大利润  LCOF
// translatedTitle:股票的最大利润
// questionId:100344
// time:2022-10-16 23:11:20

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>V=prices;
        for(int i=(int)V.size()-2;i>=0;i--)V[i]=max(V[i],V[i+1]);
        int ans=0;
        for(int i=0;i+1<V.size();i++){
            ans=max(ans,V[i]-prices[i]);
        }
        return ans;
    }
};