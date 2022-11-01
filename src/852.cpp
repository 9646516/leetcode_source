// id:374011399
// runtime:88 ms
// memory:58.2 MB
// title:Peak Index in a Mountain Array
// translatedTitle:山脉数组的峰顶索引
// questionId:882
// time:2022-10-17 23:41:51

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int L=1,R=arr.size()-1,ans=0;
        while(L<=R){
            int mid=(L+R)/2;
            if(arr[mid]>arr[mid-1]){
                ans=mid;
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        return ans;
    }
};