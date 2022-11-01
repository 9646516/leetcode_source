// id:374632618
// runtime:8 ms
// memory:12 MB
// title:Search Rotate Array LCCI
// translatedTitle:搜索旋转数组
// questionId:100232
// time:2022-10-19 21:36:11

class Solution {
public:
    int search(vector<int>& arr, int target) {
        while(arr.size()>1&&arr.back()==arr.front())arr.pop_back();
        int L=1,R=arr.size(),ans=0;
        while(L<=R){
            int mid=(L+R)/2;
            if(arr[mid]>=arr[0]){
                ans=mid;
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        auto p1=lower_bound(arr.begin(),arr.begin()+ans+1,target);
        if(p1!=arr.begin()+ans+1&&*p1==target)return p1-arr.begin();
        auto p2=lower_bound(arr.begin()+ans+1,arr.end(),target);
        if(p2!=arr.end()&&*p2==target)return p2-arr.begin();
        return -1;
    }
};