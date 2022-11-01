// id:373643563
// runtime:16 ms
// memory:6.6 MB
// title:和为s的连续正数序列 LCOF
// translatedTitle:和为s的连续正数序列
// questionId:100324
// time:2022-10-16 22:11:52

class Solution {
public:
    using ll=long long;
    int solve(int target,int F){
        ll L=1,R=1e4,ans=1e4;
        while(L<=R){
            ll mid=(L+R)/2;
            ll xs=(F+F+mid-1)*mid/2;
            if(xs>=target){
                ans=mid;
                R=mid-1;
            }else{
                L=mid+1;
            }
        }
        ll xs=(F+F+ans-1)*ans/2;
        if(xs==target)return ans;
        else return -1;
    }
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>ret;
        for(int i=1;i<target;i++){
            int sz=solve(target,i);
            if(sz!=-1){
                ret.push_back({});
                for(int j=0;j<sz;j++){
                    ret.back().push_back(i+j);
                }
            }
        }
        return ret;
    }
};