// id:374151019
// runtime:0 ms
// memory:5.8 MB
// title:求平方根
// translatedTitle:求平方根
// questionId:1000336
// time:2022-10-18 14:39:54

class Solution {
public:
    using ll=long long;
    int mySqrt(int x) {
        ll L=0,R=1e5,ans;
        while(L<=R){
            ll mid=(L+R)/2;
            if(mid*mid<=x){
                ans=mid;
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        return ans;
    }
};