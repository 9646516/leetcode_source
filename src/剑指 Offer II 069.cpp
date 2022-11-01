// id:374010116
// runtime:4 ms
// memory:11.3 MB
// title:山峰数组的顶部
// translatedTitle:山峰数组的顶部
// questionId:1000333
// time:2022-10-17 23:37:17

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