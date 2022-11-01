// id:373276557
// runtime:4 ms
// memory:11.9 MB
// title:旋转数组的最小数字  LCOF
// translatedTitle:旋转数组的最小数字
// questionId:100278
// time:2022-10-15 19:27:45

class Solution {
public:
    int minArray(vector<int>& V) {
        return *min_element(V.begin(),V.end());
        // int L=0,R=V.size()-1,ans=0;
        // while(L<=R){
        //     int mid=(L+R)/2;
        //     if(V[mid]>=V[0]){
        //         ans=mid;
        //         L=mid+1;
        //     }else{
        //         R=mid-1;
        //     }
        // }
        // if(ans==V.size()-1){
        //     return V[0];
        // }else{
        //     return V[ans+1];
        // }
    }
};